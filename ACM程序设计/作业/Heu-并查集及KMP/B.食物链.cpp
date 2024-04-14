#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;

int n,m,ans;
int fa[maxn*3];

int find(int u){
	return fa[u]==u ? u : fa[u]=find(fa[u]);
}

int main(){
//	freopen("input.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n * 3; ++i) fa[i] = i;
	while(m--){
		int opt,u,v;
		scanf("%d%d%d",&opt,&u,&v);
		if(u>n || v>n){
			++ans;
			continue;
		}
		if(opt==1){
			if(find(u+n)==find(v) || find(u)==find(v+n)) ++ans;
			else{
				fa[find(u)] = find(v);
				fa[find(u+n)] = find(v+n);
				fa[find(u+2*n)] = find(v+2*n);
			}
		}
		else{
			if(find(u)==find(v) || find(u)==find(v+n)) ++ans;
			else{
				fa[find(u+n)] = find(v);
				fa[find(u+2*n)] = find(v+n);
				fa[find(u)] = find(v+2*n);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
