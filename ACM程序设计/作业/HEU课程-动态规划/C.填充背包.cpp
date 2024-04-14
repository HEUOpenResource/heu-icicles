#include<bits/stdc++.h>
#define int long long
#define FOR(a,b,c) for(int a=(b),a##_end=(c);a<=a##_end;++a)
#define ROF(a,b,c) for(int a=(b),a##_end=(c);a>=a##_end;--a)
using namespace std;
int n, v;
int c[500], dp[500][200001];
signed main(){
	int v, n;
	scanf("%lld%lld", &v, &n);
    FOR(i, 1, n) scanf("%lld", &c[i]);
    FOR(i, 1, n)
    	FOR(j, 1, v){
    		if(c[i] > j)
				dp[i][j] = dp[i - 1][j];
    		else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + c[i]);
		}
	printf("%lld", v - dp[n][v]);
	return 0;
}
