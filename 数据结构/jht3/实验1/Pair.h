#pragma once
#include<utility>
template<typename T1, typename T2> class Pair {
public :
	T1 first;
	T2 second;
	template<typename T12,typename T22>
	Pair(T12 &&first,T22 &&second):first(std::forward<T12>(first)),second(std::forward<T22>(second)) {}
	Pair() {}
};