#include<bits/stdc++.h>
#define FOR(a,b,c) for(int a=(b),a##_end=(c);a<=a##_end;++a)
#define int long long
using namespace std;
int n, m, c;
int x[100050], y[100050];
int cnt[10];
int dir[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
signed main() {
	ios::sync_with_stdio(false);
	map<pair<int, int>, int> mp;
	cin >> n >> m >> c;
	FOR(i, 1, c){
		cin >> x[i] >> y[i];
	}
	cnt[0] = n * m;
	FOR(i, 1, 8)
		cnt[i] = 0;
	FOR(i, 1, c){
		FOR(j, 0, 7){
			int xx = x[i] + dir[j][0], yy = y[i] + dir[j][1];
			if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
			--cnt[mp[{xx, yy}]];
			++mp[{xx, yy}];
			++cnt[mp[{xx, yy}]];
		}
	}
	FOR(i, 1, c){
		int xx = x[i], yy = y[i];
		--cnt[mp[{xx, yy}]];
	}
	FOR(i, 0, 8){
		cout << cnt[i] << endl;
	}
	return 0;
}
