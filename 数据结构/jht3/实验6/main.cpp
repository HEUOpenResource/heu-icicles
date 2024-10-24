#include"Pair.h"
#include"LinkedList.h"
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<functional>
using std::swap;
using std::function;
int main() {
	Pair<int, int> arr[512];
	for (int i = 0; i < 512; ++i) {
		arr[i].first = i+1;
		arr[i].second = rand() % 1000;
	}
	for (int i = 0; i < 512; ++i) {
		printf("id:%-3d score:%-3d\n", arr[i].first, arr[i].second);
	}
	//循序查找法
	auto shun_xu=[&arr]()->void {
		auto max1 = arr[0], max2 = arr[1];
		if (arr[0].second < arr[1].second)swap(max1, max2);
		for (int i = 2; i < 512; ++i) {
			if (arr[i].second > max1.second) {
				max2 = max1;
				max1 = arr[i];
			}
			else if (arr[i].second > max2.second) {
				max2 = arr[i];
			}
		}
		printf("id:%-3d score:%-3d\n", max1.first, max1.second);
		printf("id:%-3d score:%-3d\n", max2.first, max2.second);
	};
	//锦标赛法
	auto jin_biao_sai = [&arr]()->void {
		LinkedList<Pair<int, int>> li;
		LinkedList<Pair<int, int>> lis[512];
		for (int i = 0; i < 512; ++i) {
			li.add(arr[i]);
		}
		while (li.size() != 1) {
			LinkedList<Pair<int, int>> li2;
			for (auto i = li.getHead(); i; i = i->getNext()->getNext()) {
				auto p1 = i->data, p2 = i->getNext()->data;
				if (p1.second > p2.second) {
					li2.add(p1);
					lis[p1.first - 1].add(p2);
				}
				else {
					li2.add(p2);
					lis[p2.first - 1].add(p1);
				}
			}
			li = li2;
		}
		auto &p1 = li.get(0);
		auto &max2 = lis[p1.first - 1].get(0);
		for (auto i = lis[p1.first - 1].getHead(); i; i = i->getNext()) {
			if (i->data.second > max2.second)max2 = i->data;
		}
		printf("id:%-3d score:%-3d\n", p1.first, p1.second);
		printf("id:%-3d score:%-3d\n", max2.first, max2.second);
	};
	//大顶堆法
	auto da_ding_dui = [](Pair<int, int> arr[512])->void {
		function<void(int, Pair<int, int>[512])> sort_child = [&sort_child](int i, Pair<int,int> arr[512])->void {
			if (i * 2 >= 512)return;
			int max = 0;
			if (arr[i * 2 + 1].second > arr[i * 2].second)max = 1;
			if (arr[i].second < arr[i * 2 + max].second) {
				swap(arr[i], arr[i * 2 + max]);
				sort_child(i * 2 + max,arr);
			}
		};
		for (int i = 255; i >= 0; --i) {
			sort_child(i,arr);
		}
		printf("id:%-3d score:%-3d\n", arr[0].first, arr[0].second);
		if(arr[1].second>arr[2].second)
			printf("id:%-3d score:%-3d\n", arr[1].first, arr[1].second);
		else
			printf("id:%-3d score:%-3d\n", arr[2].first, arr[2].second);
	};
	printf("顺序查找:\n");
	shun_xu();
	printf("锦标赛查找:\n");
	jin_biao_sai();
	printf("大顶堆:\n");
	da_ding_dui(arr);
	return 0;
}