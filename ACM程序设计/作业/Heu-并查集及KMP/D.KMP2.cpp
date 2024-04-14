#include<bits/stdc++.h>
using namespace std;
char a[1000010];
char b[1000010];
int kmp_next[1000010];

void getNext(int m){
	int j = 0;
	kmp_next[0] = 0;
	for(int i = 1; i < m; ++i){
		while(j>0 && b[i]!=b[j]) j=kmp_next[j-1];
		if(b[i]==b[j]) ++j;
		kmp_next[i] = j;
	}
}

int kmp(int n,int m){
	int i, j = 0, res = 0;
	getNext(m);
	for(i = 0; i < n; ++i){
		while(j>0 && b[j]!=a[i]) j=kmp_next[j-1];
		if(b[j]==a[i]) ++j;
		if(j==m) ++res;
	}
	return res;
}

int main(){
//	freopen("input.txt","r",stdin);
	scanf("%s",a);
	scanf("%s",b);
	int n=strlen(a);
	int m=strlen(b);
	int t = kmp(n,m);
	t==0?printf("No\n"):printf("%d\n",t);
	return 0;
}
