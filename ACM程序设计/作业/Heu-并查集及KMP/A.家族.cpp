#include<bits/stdc++.h>
using namespace std;
int fa[100010];
int find(int x){
	return fa[x]==x ? x : fa[x]=find(fa[x]);
}

int main(){
	freopen("input.txt","r",stdin);
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	for(int i = 1; i <= n; ++i) fa[i]=i;
	int x,y;
	while(m--){
		scanf("%d%d",&x,&y);
		fa[find(y)]=find(x);
	}
	while(q--){
		scanf("%d%d",&x,&y);
		if(find(x)==find(y)){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}
