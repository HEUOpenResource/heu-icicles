#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int a[maxn+2];

struct node{
    int l,r;
    int val;
	int lazy;
}t[4*maxn+2];

void build(int u,int l,int r){
	t[u].l=l;
	t[u].r=r;
	if(l==r){
		t[u].val=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(u*2,l,mid);
	build(u*2+1,mid+1,r);
	t[u].val=t[u*2].val+t[u*2+1].val;
}

void pushup(int u){
	t[u].val=t[u*2].val+t[u*2+1].val;
}

void pushdown(int u) {
	t[u << 1].lazy += t[u].lazy;
	t[u << 1 | 1].lazy += t[u].lazy;
	t[u << 1].val += t[u].lazy * (t[u << 1].r - t[u << 1].l + 1);
	t[u << 1 | 1].val += t[u].lazy * (t[u << 1 | 1].r - t[u << 1 | 1].l + 1);
	t[u].lazy = 0;
}

void modify2(int u, int l, int r, int x) {
	if (l <= t[u].l and t[u].r <= r) {
		t[u].lazy += x;
		t[u].val += x * (t[u].r - t[u].l + 1);
		return;
	}
	int mid = (t[u].l + t[u].r) >> 1;
	pushdown(u);
	if (l <= mid) modify2(u << 1, l, r, x);
	if (mid < r) modify2(u << 1 | 1, l, r, x);
	pushup(u);
}

int query(int u,int L,int R){
	if(t[u].l>R||t[u].r<L) return 0;
	if(t[u].l>=L&&t[u].r<=R) return t[u].val;
	pushdown(u);
	return query(u*2,L,R)+query(u*2+1,L,R);
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	while(m--){
		string op;
		cin>>op;
		if(op=="modify"){
			int x,y,t;
			scanf("%d%d%d",&x,&y,&t);
			modify2(1,x,y,t);
		}
		else{
			int L,R;
			scanf("%d%d",&L,&R);
			int ans=query(1,L,R);
			printf("%d\n",ans);
		}
	}
	return 0;
}//
