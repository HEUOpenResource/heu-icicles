#include<bits/stdc++.h>
using namespace std;
int m, d, x;
string op;
int t = 0, j = 0;
int a[1000010];
int main(){
  	scanf("%d%d", &m, &d);
    while(m--){
        cin >> op;
       	scanf("%d", &x);
        if(op == "A"){
            x = (x + t) % d;
            a[++j] = x;
            for(int i = j - 1; i >= 1; --i){
                if(a[i] < x) a[i] = x;
                else break;
            }
        }
        else{
            printf("%d\n", a[j - x + 1]);
            t = a[j - x + 1];
        }
    }
    return 0;
}
