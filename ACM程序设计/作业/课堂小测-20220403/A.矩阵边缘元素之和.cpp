#include<bits/stdc++.h>
using namespace std;
int a[105][105];
int m, n;
int ans = 0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> m >> n;
	for(int i = 1; i <= m; ++i){
		for(int j = 1; j <= n; ++j){
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= n; ++i){
		ans += a[1][i];
		ans += a[m][i];
	}
	for(int i = 1; i <= m; ++i){
		ans += a[i][1];
		ans += a[i][n];
	}
	ans = ans - a[1][1] - a[1][n] - a[m][1] - a[m][n];
	cout << ans << endl;
	return 0;
}
