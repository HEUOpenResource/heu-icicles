#include<bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;
int a[maxn];

struct node{
    int l,r;
    int val;
}tr[4*maxn+2];
void pushup(int u){
    tr[u].val=min(tr[u*2].val,tr[u*2+1].val);
}
void build(int u,int l,int r){
    tr[u].l=l;
    tr[u].r=r;
    if(l==r){
        tr[u].val=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(u*2,l,mid);
    build(u*2+1,mid+1,r);
    pushup(u);
}
int query(int u,int L,int R){
    if(L<=tr[u].l&&tr[u].r<=R)
        return tr[u].val;
    int ans=0x3f3f3f3f;
    int mid=(tr[u].l+tr[u].r)/2;
    if(L<=mid)
        ans=min(ans,query(u*2,L,R));
    if(R>mid)
        ans=min(ans,query(u*2+1,L,R));
    return ans;
}
void modify(int u,int x,int v){
    if(tr[u].l==tr[u].r){
        tr[u].val=v;
        return;
    }
    int mid=(tr[u].l+tr[u].r)/2;
    if(x<=mid)
        modify(u*2,x,v);
    else
        modify(u*2+1,x,v);
    pushup(u);
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	build(1,1,n);
	while(m--){
		int o,x,y;
		scanf("%d%d%d",&o,&x,&y);
		if(o==1){
			printf("%d ",query(1,x,y));
		}
		else{
			modify(1,x,y);
		}
	}
	return 0;
}
