#include<bits/stdc++.h>
#define int long long
using namespace std;
int x, y, z;
int a[1005], b[1005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> x >> y >> z;
	for(int i = 1; i <= x; ++i){
		a[i] = 1;
		b[i] = 0;
	}
	for(int i = x + 1; i <= z + 1; ++i){
		b[i] = y * a[i - x];
		a[i] = a[i - 1] + b[i - 2];
	}
	cout << a[z + 1]<< endl;
	return 0;
}
