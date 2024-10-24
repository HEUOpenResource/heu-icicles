#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<iostream>
#include<stdio.h>
#include"LinkedList.h"
#include"CycleLinkedList.h"
using std::string;
using std::cout;
using std::endl;
class Node {
private:
	//辅助打印节点的方法
	void printLevel() {
		if (parient) {
			parient->printLevel();
		}
		cout << "│ ";
	}
public:
	enum class Types
	{
		CLASS=0,TEACHER=1, GRADUATE_STUDENT=2, UNGRADUATE_STUDENT=3
	};
	string name;
	string info;
	Types type;
	Node* parient;
	LinkedList<Node*> child;
	Node(string name,Types type):name(name),type(type),parient(nullptr){}
	Node(string name,Types type, Node* parient) :name(name), type(type), parient(parient) {
		parient->child.add(this);
	}
	//打印节点
	void printNode() {
		cout << name << endl;
		for (auto i = child.getHead(); i; i = i->getNext()) {
			if (parient)parient->printLevel();
			cout << "├ ";
			i->data->printNode();
		}
	}
	//添加一个子节点
	void addChild(Node* child) {
		this->child.add(child);
		child->parient = this;
	}
	Node* search(string s) {
		if (name == s)return this;
		else {
			for (auto i = child.getHead(); i; i = i->getNext()) {
				if (i->data->name == s)return i->data;
				else {
					auto ret = i->data->search(s);
					if (ret)return ret;
				}
			}
		}
		return nullptr;
	}
	//添加一堆子节点并尝试将子节点分摊到研究生子节点下
	void addChild(LinkedList<Node*> child) {
		CycleLinkedList<Node*> gs;
		for (auto i = this->child.getHead(); i; i = i->getNext()) {
			if ((this->type==Node::Types::TEACHER&&i->data->type == Node::Types::GRADUATE_STUDENT)
				||(this->type==Node::Types::CLASS))gs.add(i->data);
		}
		if (!gs.isEmpty()) {
			auto temp = gs.getHead();
			for (auto i = child.getHead(); i; i = i->getNext(),temp=temp->getNext()) {
				temp->data->addChild(i->data);
			}
		}
		else {
			this->child.addAll(child);
		}
	}
	void changeParient(Node *n) {
		remove();
		n->addChild(this);
	}
	void moveChild(Node* n) {
		n->addChild(child);
		child.clear();
	}
	void remove() {
		if (parient) {
			for (auto i = parient->child.getHead(); i; i = i->getNext()) {
				if (i->data == this) {
					parient->child.remove(i);
					break;
				}
			}
			parient->addChild(child);
		}
		child.clear();
	}
	int size() {
		int total = 0;
		for (auto i = child.getHead(); i; i = i->getNext()) {
			total += i->data->size();
		}
		return child.size() + total;
	}
};
int main() {
	//建立
	Node classes("班级1", Node::Types::CLASS);
	//插入
	Node teacher("老师1", Node::Types::TEACHER,&classes);
	Node ung1("本科生1", Node::Types::UNGRADUATE_STUDENT,&teacher);
	Node ung2("本科生2", Node::Types::UNGRADUATE_STUDENT, &teacher);
	Node g1("研究生1", Node::Types::GRADUATE_STUDENT, &teacher);
	Node ung3("本科生3", Node::Types::UNGRADUATE_STUDENT, &g1);
	Node ung4("本科生4", Node::Types::UNGRADUATE_STUDENT, &g1);
	Node g2("研究生2", Node::Types::GRADUATE_STUDENT, &teacher);
	Node teacher2("老师2", Node::Types::TEACHER, &classes);
	Node ung5("本科生5", Node::Types::UNGRADUATE_STUDENT, &teacher2);
	Node ung6("本科生6", Node::Types::UNGRADUATE_STUDENT, &teacher2);
	Node teacher3("老师3", Node::Types::TEACHER, &classes);
	Node g3("研究生3", Node::Types::GRADUATE_STUDENT, &teacher);
	Node g4("研究生4", Node::Types::GRADUATE_STUDENT, &teacher);
	Node ung7("本科生7", Node::Types::UNGRADUATE_STUDENT, &g3);
	Node ung8("本科生8", Node::Types::UNGRADUATE_STUDENT, &g3);
	//查询
	auto ans = classes.search("本科生3");
	printf("查询结果:%s\n", ans->name.c_str());
	//输出
	classes.printNode();
	//删除+思考3
	printf("总人数:%d\n", classes.size());
	printf("删除研究生1节点\n");
	g1.remove();
	classes.printNode();
	//统计
	printf("总人数:%d\n", classes.size());
	printf("删除研究生2节点\n");
	g2.remove();
	classes.printNode();
	printf("总人数:%d\n", classes.size());
	//思考4
	printf("删除导师2\n");
	teacher2.remove();
	classes.printNode();
	//思考1
	printf("将本科生4转移到教师3名下\n");
	ung4.changeParient(&teacher3);
	classes.printNode();
	//思考2
	printf("将研究生3的学生转移到研究生4名下\n");
	g3.moveChild(&g4);
	classes.printNode();
	return 0;
}