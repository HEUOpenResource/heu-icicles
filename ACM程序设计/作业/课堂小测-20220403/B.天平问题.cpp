#include<bits/stdc++.h>
#define int long long
using namespace std;
bool mk[100010];
int dp[100010];
int a, n, k, ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	dp[0] = 50000;
	for(int i = 1; i <= n; ++i){
		cin >> a;
		k = ans;
		for(int j = 0; j <= k; ++j){
			if(mk[dp[j] + a] == 0){
		  	    mk[dp[j] + a] = 1;
		  	    dp[++ans] = dp[j] + a;
		    }
			if(mk[dp[j] - a] == 0){
				mk[dp[j] - a] = 1;
				dp[++ans] = dp[j] - a;
			}
		}
	}
	cout << ans / 2 << endl;
	return 0;
}

