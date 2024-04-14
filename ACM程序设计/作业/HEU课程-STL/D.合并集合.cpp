#include<bits/stdc++.h>
using namespace std;
int n, m;
int main(){
	ios::sync_with_stdio(false);
	while(cin >> n >> m){
		set<int> s;
		int t;
		while(n--){
			cin >> t;
			s.insert(t);
		}
		while(m--){
			cin >> t;
			s.insert(t);
		}
		for(auto i = s.begin(); i != s.end(); ++i){
			cout << *i << " ";
		}
		cout << endl;
	}
	return 0;
}
