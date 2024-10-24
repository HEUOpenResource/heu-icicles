#include<fstream>
#include<string>
#include<iostream>
#include<iomanip>
#include"LinkedList.h"
#include"Pair.h"
using std::left;
using std::setw;
using std::string;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::wcout;
using std::cin;
using std::cout;
struct Course {
	string name_id;
	string name;
	int score=0;
	int id=0;
};
void solute(int mode,const string path) {
	//读取数据
	ifstream f(path);
	int total;
	f >> total;
	struct Course* courses = new Course[total];
	for (int i = 0; i < total; ++i) {
		f >> courses[i].name_id >> courses[i].name >> courses[i].score;
		courses[i].id = i;
	}
	int** arr = new int* [total];
	for (int i = 0; i < total; ++i) {
		arr[i] = new int[total];
		for (int j = 0; j < total; ++j) {
			arr[i][j] = 0;
		}
	}
	int links;
	f >> links;
	for (int i = 0; i < links; ++i) {
		int a, b;
		f >> a >> b;
		arr[a][b] = 1;
	}
	f.close();
	//处理问题
	const int TERM = 8, CLASS = 5;
	int rest = total;
	for (int i = 0; i < TERM; ++i) {
		/*
		for (int j = 0; j < total; ++j) {
			for (int k = 0; k < total; ++k)
				cout << arr[j][k] << ' ';
			cout << endl;
		}
		*/
		cout << "第 " << i + 1 << " 学期" << endl;
		//选择 把这学期能学的课找出来
		LinkedList<Course*> target;
		for (int j = 0,flag=0; j < total;++j,flag=0) {
			for (int k = 0; k < total; ++k) {
				if (arr[k][j]!=0) {
					flag = 1;
					break;
				}
			}
			if (!flag)target.add(&courses[j]);
		}
		//排序 把重要的课排前面
		target.sort([total,arr](Course* const& a, Course* const& b)->bool {
			int a1 = 0, b1 = 0;
			for (int i = 0; i < total; ++i) {
				if (arr[a->id][i]==1)++a1;
				if (arr[b->id][i]==1)++b1;
			}
			return a1 < b1;
			});
		//决定这学期学的课
		int termClass = ceil((double)rest / (TERM - i));
		if (termClass > 5) {
			cout << "课程过多 无解" << endl;
			break;
		}
		if (mode == 1)
			termClass = 5;
		int temp = 0;
		int termScore = 0;
		for (auto j = target.getHead(); j && temp < termClass; (j = j->getNext()),temp++) {
			cout << j->data->name_id << " " << j->data->name<<endl;
			--rest;
			termScore += j->data->score;
			for (int k = 0; k < total; ++k) {
				if(arr[j->data->id][k]!=-1)
					arr[j->data->id][k] = 0;
			}
			for (int k = 0; k < total; ++k) {
				arr[k][j->data->id] = -1;
			}
		}
		if (termScore == 0 && rest != 0) {
			cout << "课程存在闭环" << endl;
			break;
		}
		cout << "第 " << i+1 << " 学期总学分为 " << termScore << " 分" << endl;
	}
	if (rest) {
		cout << "课程过多或存在闭环" << endl;
	}
	//释放内存
	for (int i = 0; i < total; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
	delete[] courses;
}
void edit(const string path) {
	//读取数据
	ifstream f(path);
	int classTotal;
	f >> classTotal;
	LinkedList<Course> courses;
	for (int i = 0; i < classTotal; ++i) {
		Course c;
		c.id = i;
		f >> c.name_id >> c.name >> c.score;
		courses.add(c);
	}
	int arrTotal;
	f >> arrTotal;
	LinkedList<Pair<int, int>> arr;
	for (int i = 0; i < arrTotal; ++i) {
		int a, b;
		f >> a >> b;
		arr.add(Pair<int,int>( a,b ));
	}
	f.close();

	auto printData = [&courses, &arr]()->void {
		cout << "-------------------------------------------" << endl;
		cout << "课程id 课程编号 课程名称       课程学分" << endl;
		for (auto i = courses.getHead(); i; i = i->getNext()) {
			cout << left << setw(7) << i->data.id;
			cout << left << setw(9) << i->data.name_id;
			cout << left << setw(15) << i->data.name;
			cout << i->data.score << endl;
		}
		for (auto i = courses.getHead(); i; i = i->getNext()) {
			cout << left << setw(15) << i->data.name << " 的前置课程:";
			for (auto j = arr.getHead(); j; j = j->getNext()) {
				if (j->data.second==i->data.id)
					cout << courses.get(j->data.first).name << ' ';
			}
			cout << endl;
		}
		cout << "-------------------------------------------" << endl;
	};
	auto printPanel = []()->void {
		cout << "1.增加课程" << endl;
		cout << "2.删除课程" << endl;
		cout << "3.修改课程信息" << endl;
		cout << "4.删除课程关系" << endl;
		cout << "5.添加课程关系" << endl;
		cout << "6.打印课程信息" << endl;
		cout << "其他.保存并退出" << endl;
	};
	auto addClass = [&courses]()->void {
		string name_id, name;
		int score;
		int id = courses.getEnd()->data.id + 1;
		cout << "输入课程编号" << endl;
		cin >> name_id;
		cout << "输入课程名称" << endl;
		cin >> name;
		cout << "输入课程学分" << endl;
		cin >> score;
		for (auto i = courses.getHead(); i; i = i->getNext()) {
			if (i->data.name_id == name_id) {
				cout << "课程信息重复" << endl;
				return;
			}
		}
		cout << "添加课程成功 课程id:" << id << endl;
		courses.add(Course{ name_id,name,score,id });
	};
	auto removeClass = [&courses,&arr]()->void {
		cout << "输入课程id" << endl;
		int id;
		cin >> id;
		for (auto i = courses.getHead(); i; i = i->getNext()) {
			if (i->data.id == id) {
				courses.remove(i);
				for (auto j = arr.getHead(),temp=j; j; j = temp) {
					temp = j->getNext();
					if (j->data.first == id || j->data.second == id)
						arr.remove(j);
				}
				cout << "移除课程完成" << endl;
				return;
			}
		}
		cout << "课程未找到" << endl;
		return;
	};
	auto editClass = [&courses]()->void {
		int id;
		cout << "输入课程id" << endl;
		cin >> id;
		for (auto i = courses.getHead(); i; i = i->getNext()) {
			if (i->data.id == id) {
				string name_id, name;
				int score;
				cout << "输入课程编号" << endl;
				cin >> name_id;
				cout << "输入课程名称" << endl;
				cin >> name;
				cout << "输入课程学分" << endl;
				cin >> score;
				for (auto j = courses.getHead(); j; j = j->getNext()) {
					if ((j->data.name_id == name_id) && (j->data.id != id)) {
						cout << "课程信息重复" << endl;
						return;
					}
				}
				i->data.name = name;
				i->data.name_id = name_id;
				i->data.score = score;
				cout << "修改课程信息成功" << endl;
				return;
			}
		}
		cout << "课程未找到" << endl;
	};
	auto removArr = [&arr]()->void{
		int a, b;
		cout << "请输入课程id a,b(即a是b的前置课程)" << endl;
		cin >> a >> b;
		for (auto i = arr.getHead(); i; i = i->getNext()) {
			if (i->data.first == a && i->data.second == b) {
				arr.remove(i);
				cout << "删除完成" << endl;
				return;
			}
		}
		cout << "未找到关系" << endl;
	};
	auto addArr = [&courses, &arr]()->void {
		cout << "请输入课程id a,b(即a是b的前置课程)" << endl;
		int a, b;
		int flag1=0, flag2=0;
		cin >> a >> b;
		for (auto i = courses.getHead(); i; i = i->getNext()) {
			if (i->data.id == a)flag1 = 1;
			if (i->data.id == b)flag2 = 1;
		}
		if (!(flag1 && flag2)) {
			cout << "课程不存在" << endl;
			return;
		}
		for (auto i = arr.getHead(); i; i = i->getNext()) {
			if (i->data.first == a && i->data.second == b) {
				cout << "关系已存在" << endl;
				return;
			}
		}
		arr.add(Pair<int, int>(a, b));
		cout << "添加关系完成" << endl;
	};
	auto save = [&courses, &arr,&path]()->void {
		ofstream f(path);
		f << courses.size()<<endl;
		int j = 0;
		int *map=new int[courses.getEnd()->data.id+1];
		for (auto i = courses.getHead(); i; (i = i->getNext()),++j) {
			f << i->data.name_id << ' ' << i->data.name << ' ' << i->data.score << endl;
			map[i->data.id] = j;
		}
		f << arr.size()<<endl;
		for (auto i = arr.getHead(); i; i = i->getNext()){
			f << map[i->data.first] << ' ' << map[i->data.second] << endl;
		}
		delete[] map;
		f.close();	
	};
	printData();
	while (true) {
		printPanel();
		int i;
		cin >> i;
		switch (i) {
		case 1:
			addClass();
			break;
		case 2:
			removeClass();
			break;
		case 3:
			editClass();
			break;
		case 4:
			removArr();
			break;
		case 5:
			addArr();
			break;
		case 6:
			printData();
			break;
		default:
			save();
			return;
		}
	}
}
int main() {
	while (true) {
		cout << "-------------------" << endl;
		cout << "1.平均分配学习计划" << endl;
		cout << "2.最短分配学习计划" << endl;
		cout << "3.修改课程表" << endl;
		cout << "-------------------" << endl;
		int num;
		cin >> num;
		switch (num) {
		case 1:
			cout << "------------平均分配学习计划------------" << endl;
			solute(0, R"(I:\Demo\实验5\Project1\data.in)");
			break;
		case 2:
			cout << "------------最短学习计划分配------------" << endl;
			solute(1, R"(I:\Demo\实验5\Project1\data.in)");
			break;
		case 3:
			edit(R"(I:\Demo\实验5\Project1\data.in)");
			break;
		}
	}
	return 0;
}