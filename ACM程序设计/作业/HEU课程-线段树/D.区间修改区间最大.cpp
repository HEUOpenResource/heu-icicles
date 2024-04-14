#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int a[maxn+2];

struct node{
	int l,r;
	int maxv;
	int lazy;
}t[maxn*4+2];

void pushup(int u){
	t[u].maxv=max(t[u*2].maxv,t[u*2+1].maxv);
}

void pushdown(int u){
	t[u*2].lazy+=t[u].lazy;
	t[u*2+1].lazy+=t[u].lazy;
	t[u*2].maxv+=t[u].lazy;
	t[u*2+1].maxv+=t[u].lazy;
	t[u].lazy=0;
}

void build(int u,int l,int r){
	t[u].l=l;
	t[u].r=r;
	if(l==r){
		t[u].maxv=a[l];
		return;
	}
	int mid=(t[u].l+t[u].r)/2;
	build(u*2,l,mid);
	build(u*2+1,mid+1,r);
	pushup(u);
}

void modify(int u,int l,int r,int x){
	if(t[u].l>r||t[u].r<l) return;
	if(t[u].l>=l&&t[u].r<=r){
		t[u].lazy+=x;
		t[u].maxv+=x;
		return;
	}
	int mid=(t[u].l+t[u].r)/2;
	pushdown(u);
	modify(u*2,l,r,x);
	modify(u*2+1,l,r,x);
	pushup(u);
}

int query(int u,int l,int r){
	if(t[u].l>r||t[u].r<l) return -1e9;
	if(t[u].l>=l&&t[u].r<=r){
		return t[u].maxv;
	}
	int mid=(t[u].l+t[u].r)/2;
	pushdown(u);
	int ans = -1e9;
	ans = max(ans, query(u*2,l,r));
	ans = max(ans, query(u*2+1,l,r));
	pushup(u);
	return ans;
}

int main(){
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	build(1,1,n);
	int op,l,r;
	scanf("%d",&m);
	while(m--){
		scanf("%d%d%d",&op,&l,&r);
		if(op==1){
			int c;
			scanf("%d",&c);
			modify(1,l,r,c);
		}
		else{
			printf("%d\n",query(1,l,r));
		}
	}
	return 0;
}

