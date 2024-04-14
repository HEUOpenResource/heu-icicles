#include<bits/stdc++.h>
#define int long long
#define FOR(a,b,c) for(int a=(b),a##_end=(c);a<=a##_end;++a)
#define ROF(a,b,c) for(int a=(b),a##_end=(c);a>=a##_end;--a)
using namespace std;
int n;
int dp[1005];
bool b[1005];
signed main(){
	FOR(i, 2, 1000)
		if(!b[i])
			for(int j = 2; i * j <= 1000; ++j)
				b[i * j] = 1;
	scanf("%lld", &n);
	dp[0] = 1;
	FOR(i, 2, n)
		if(!b[i])
			FOR(j, i, n)
				dp[j] += dp[j - i];
	printf("%lld", dp[n]);
  	return 0;
}
