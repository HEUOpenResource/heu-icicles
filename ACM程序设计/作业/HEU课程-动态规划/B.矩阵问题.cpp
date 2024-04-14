#include<bits/stdc++.h>
#define FOR(a,b,c) for(int a=(b),a##_end=(c);a<=a##_end;++a)
#define ROF(a,b,c) for(int a=(b),a##_end=(c);a>=a##_end;--a)
using namespace std;
int a[505][505], dp[505][505];
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	FOR(i, 1, n) FOR(j, 1, m) scanf("%d", &a[i][j]);
	FOR(i, 1, n)
		FOR(j, 1, m)
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
	printf("%d", dp[n][m]);
	return 0;
}
