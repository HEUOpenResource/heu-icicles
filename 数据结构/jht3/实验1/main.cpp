#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include"CycleLinkedList.h"
#include"Pair.h"

int main() {
	int n;
	printf("输入学生总数\n");
	scanf("%d", &n);
	printf("每人密码是否相同\n1:是\n2:否\n");
	int mode;
	scanf("%d", &mode);
	CycleLinkedList<Pair<int, int>> cl;
	if (mode==1) {
		int m;
		printf("请输入m的值\n");
		scanf("%d", &m);
		for (int i = 0; i < n; ++i) {
			cl.add(Pair<int, int>(i + 1, m));
		}
	}else {
		for (int i = 0; i < n; ++i) {
			int m;
			printf("请输入m的值\n");
			scanf("%d", &m);
			cl.add(Pair<int, int>(i + 1, m));
		}
	}
	auto data = cl.getHead();
	while (!cl.isEmpyt()) {
		int m = data->data.second;
		for (int i = 0; i < m-1; ++i) {
			data=data->getNext();
		}
		auto rm = data;
		data = data->getNext();
		printf("%d ", rm->data.first);
		cl.remove(rm);
	}
	return 0;
	
}