#include<bits/stdc++.h>
using namespace std;
int a[30005];
int main(){
	int n, k, q;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
	sort(a, a + n);
	scanf("%d", &k);
	while(k--){
		scanf("%d", &q);
		printf("%d\n", a[q -1]);
	}
	return 0;
}
