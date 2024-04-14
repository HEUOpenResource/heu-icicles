#include<bits/stdc++.h>
using namespace std;
map<string, int> mp;
int n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	string s;
	int pg;
	while(n--){
		cin >> s;
		cin >> pg;
		mp[s] = pg;
	}
	int k;
	cin >> k;
	while(k--){
		cin >> s;
		cout << mp[s] << endl;
	}
	return 0;
}
