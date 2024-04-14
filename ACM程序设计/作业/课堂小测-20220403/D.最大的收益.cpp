#include<bits/stdc++.h>
using namespace std;
int a[1005], dp[1005];
int n, ans = 0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	dp[1] = a[1];
	for(int i = 2; i <= n; ++i){
		dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
		ans = ans > dp[i] ? ans : dp[i];
	}
	cout << ans << endl;
	return 0;
}
