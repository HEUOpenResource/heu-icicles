#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<utility>
#include"Stack.h"
#include"LinkedList.h"

//3+(5/2)%4*2+(1-3)*4=-1
//2*((30/3%4*1)+22/(41-6)%4)/3=1
struct Node {
	enum class Type { OP, NUM };
	Type t;
	union {
		char op;
		int num;
	};
	Node(Type t, char data) :t(t), op(data) {};
	Node(Type t, int data) :t(t), num(data) {};
};
Node getNode(char** str) {
	if (**str >= '0' && **str <= '9') {
		int num;
		sscanf(*str, "%d", &num);
		while (**str >= '0' && **str <= '9')++(*str);
		return Node(Node::Type::NUM, num);
	}
	else {
		++(*str);
		return Node(Node::Type::OP, *(*str - 1));
	}
}
LinkedList<Node> toSuffixExp(LinkedList<Node> infixExpList) {
	LinkedList<Node> suffixExpList;
	Stack<Node> st;
	for (auto data = infixExpList.getHead(); data; data = data->getNext()) {
		if (data->data.t == Node::Type::NUM)suffixExpList.add(data->data);
		else {
			while (!st.isEmpty()) {
				if ((data->data.op == '+' || data->data.op == '-') && (st.front().op != '(')) {
					suffixExpList.add(st.front());
					st.pop();
				}
				else if ((data->data.op == '*' || data->data.op == '/' || data->data.op == '%') && (st.front().op == '*' || st.front().op == '/' || st.front().op == '%')) {
					suffixExpList.add(st.front());
					st.pop();
				}
				else if (data->data.op == ')' && st.front().op != '(') {
					suffixExpList.add(st.front());
					st.pop();
				}
				else if (data->data.op == ')' && st.front().op == '(') {
					st.pop();
					break;
				}
				else {
					break;
				}
			}
			if (data->data.op != ')')
				st.push(data->data);
		}
	}
	while (!st.isEmpty()) {
		suffixExpList.add(st.front());
		st.pop();
	}
	return suffixExpList;
}
LinkedList<Node> toPrefixExp(LinkedList<Node> infixExpList) {
	LinkedList<Node> li;
	Stack<Node> s1, s2;
	for (auto i = infixExpList.getEnd(); i; i = i->getLast()) {
		if (i->data.t == Node::Type::NUM) {
			s2.push(i->data);
		}
		else {
			char op = i->data.op;
			if (op != '(' && op != ')') {
				while (!s1.isEmpty()) {
					if ((op == '+' || op == '-') && (s1.front().op == '*' || s1.front().op == '/' || s1.front().op == '%')) {
						s2.push(s1.front());
						s1.pop();
					}
					else {
						break;
					}
				}
				s1.push(i->data);
			}
			else if (op == ')') {
				s1.push(i->data);
			}
			else {
				while (s1.front().op != ')') {
					s2.push(s1.front());
					s1.pop();
				}
				s1.pop();
			}
		}
	}
	while (!s1.isEmpty()) {
		s2.push(s1.front());
		s1.pop();
	}
	while (!s2.isEmpty()) {
		li.add(s2.front());
		s2.pop();
	}
	return li;
}
int calculatePrefixExp(LinkedList<Node> prefixExpList) {
	Stack<Node> st;
	for (auto i = prefixExpList.getHead(); i; i = i->getNext()) {
		auto data = i->data;
		while (!st.isEmpty() && st.front().t == Node::Type::NUM && data.t == Node::Type::NUM) {
			int num1 = st.front().num;
			int num2 = data.num;
			st.pop();
			char op = st.front().op;
			st.pop();
			int ans = 0;
			if (op == '+')ans = num1 + num2;
			else if (op == '-')ans = num1 - num2;
			else if (op == '*')ans = num1 * num2;
			else if (op == '/')ans = num1 / num2;
			else if (op == '%')ans = num1 % num2;
			data = Node(Node::Type::NUM, ans);
		}
		st.push(data);
	}
	return st.front().num;
}
int calculateSuffixExp(LinkedList<Node> suffixExpList) {
	Stack<Node> st;
	for (auto i = suffixExpList.getHead(); i; i = i->getNext()) {
		if (i->data.t == Node::Type::NUM)st.push(i->data);
		else {
			int num2 = st.front().num;
			st.pop();
			int num1 = st.front().num;
			st.pop();
			char op = i->data.op;
			int ans = 0;
			if (op == '+')ans = num1 + num2;
			else if (op == '-')ans = num1 - num2;
			else if (op == '*')ans = num1 * num2;
			else if (op == '/')ans = num1 / num2;
			else if (op == '%')ans = num1 % num2;
			st.push(Node(Node::Type::NUM, ans));
		}
	}
	return st.front().num;
}
void expression() {
	char str[100];
	printf("请输入表达式\n");
	scanf("%s", str);
	LinkedList<Node> infixExpList;
	LinkedList<Node> suffixExpList;
	LinkedList<Node> prefixExpList;
	char* temp = &str[0];
	while (*temp) {
		infixExpList.add(getNode(&temp));
	}
	suffixExpList = toSuffixExp(infixExpList);
	prefixExpList = toPrefixExp(infixExpList);
	/*
	for (auto data = infixExpList.getHead(); data; data = data->getNext()) {
		if (data->data.t == Node::Type::OP)printf("OP: %c\n", data->data.op);
		else printf("NUM: %d\n", data->data.num);
	}
	*/
	printf("后缀表达式:");
	for (auto data = suffixExpList.getHead(); data; data = data->getNext()) {
		if (data->data.t == Node::Type::OP)printf("%c ", data->data.op);
		else printf("%d ", data->data.num);
	}
	printf("\n");
	printf("后缀表达式求值结果:%d\n", calculateSuffixExp(suffixExpList));
	printf("前缀表达式:");
	for (auto data = prefixExpList.getHead(); data; data = data->getNext()) {
		if (data->data.t == Node::Type::OP)printf("%c ", data->data.op);
		else printf("%d ", data->data.num);
	}
	printf("\n");
	printf("前缀表达式求值结果:%d\n", calculatePrefixExp(prefixExpList));
}
//-----------------------------------------------------------------------------
struct Task {
	int id;
	int time;
	Task(int id, int time) :id(id), time(time) {}
};
//测试数据
//5
//1 3 4 2 2 7 3 5 5 4
void scheduling() {
	int n;
	printf("请输入任务总数\n");
	scanf("%d", &n);
	printf("请输入任务id与任务时长\n");
	LinkedList<Task> li;
	for(int i = 0,id,time; i < n; ++i) {
		scanf("%d%d", &id, &time);
		li.add(Task(id,time));
	}
	printf("顺序执行等待时长:\n");
	li.sort([](const Task& a, const Task& b)->bool {return a.id < b.id; });
	int use = 0;
	int wait = 0;
	for (auto i = li.getHead(); i; i = i->getNext()) {
		wait += use;
		printf("任务编号:%d 执行时间:%d 起始时间:%d 终止时间:%d\n", i->data.id,i->data.time,use,i->data.time+use);
		use += i->data.time;
	}
	printf("平均等待时间:%.1lf\n", (double)wait / li.size());
	printf("最短执行等待时长:\n");
	li.sort([](const Task& a, const Task& b)->bool {return a.time < b.time; });
	use = 0;
	wait = 0;
	for (auto i = li.getHead(); i; i = i->getNext()) {
		wait += use;
		printf("任务编号:%d 执行时间:%d 起始时间:%d 终止时间:%d\n", i->data.id, i->data.time, use, i->data.time + use);
		use += i->data.time;
	}
	printf("最短等待时间:%.1lf\n", (double)wait / li.size());
}
int main() {
	printf("请输入序号\n1.表达式求值问题\n2.任务调度问题\n");
	int n;
	scanf("%d", &n);
	if (n == 1) {
		expression();
	}else if (n == 2) {
		scheduling();
	}
	return 0;
}