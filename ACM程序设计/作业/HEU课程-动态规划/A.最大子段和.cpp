#include<bits/stdc++.h>
#define FOR(a, b, c) for(int a = (b), a##_end = (c);a <= a##_end; ++a)
using namespace std;
int n;
int a[200010], b[200010];
int ans = -0x3f3f3f;
int main(){
    scanf("%d", &n);
	FOR(i, 1, n){
        scanf("%d", &a[i]);
    	if(i == 1)
    		b[i] = a[i];
    	else
    		b[i] = max(a[i], b[i - 1] + a[i]);
    	ans = max(ans, b[i]);
   }
   printf("%d", ans);
   return 0;
}
