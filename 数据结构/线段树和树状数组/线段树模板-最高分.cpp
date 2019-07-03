#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 30000
using namespace std;
struct area{
    int l,r;
    int value;
}segment[MAXN * 4];
int A[MAXN * 4];
void buildup(int p,int l,int r){
    if(l == r) {
        segment[p].value = A[l];
        segment[p].l = l;
        segment[p].r = r;
        return ;
    }
    else{
        int mid = (l + r) / 2;
        buildup(p * 2, l, mid);
        buildup(p * 2 + 1, mid + 1, r);
        segment[p].value = max(segment[p * 2].value ,segment[p * 2 + 1].value);
        segment[p].l = l;
        segment[p].r = r;
        return ;
    }
}
int query(int p,int l,int r){
    if(l <= segment[p].l  && r >= segment[p].r){
        return segment[p].value;
    }
    int returnValue = 0;
    int mid = (segment[p].l + segment[p].r) / 2;
    if(l <= mid) returnValue = max(query(p * 2, l, r),returnValue);
    if(r > mid) returnValue = max(query(p * 2 + 1, l, r),returnValue);
    return returnValue;
}
void add(int p,int x,int v){
    if(segment[p].l == x && segment[p].r == x){
        segment[p].value = v;
        return ;
    }
    int mid = (segment[p].l + segment[p].r) / 2;
    if(x <= mid) add(p * 2,x,v);
    if(x > mid) add(p * 2 + 1, x, v);
    segment[p].value = max(segment[p * 2].value, segment[p * 2 + 1].value);
    return ;
}
void clear(){
    memset(segment,0,sizeof(segment));
    memset(A, 0, sizeof(A));
}
int main(int argc, const char * argv[]) {
    int amount,n;
    while(scanf("%d%d",&amount,&n) != EOF){
        for (int i = 1; i <= amount; i ++) {
            scanf("%d",&A[i]);
        }
        
        buildup(1,1,amount);
        string command;
        for (int i = 1; i <= n; i ++){
            cin>>command;
            if (command == "Q") {
                int x,y;
                scanf("%d%d",&x,&y);
                printf("%d\n",query(1, x, y));
            }
            if (command == "U") {
                int x,y;
                scanf("%d%d",&x,&y);
                add(1, x, y);
            }
        }
        clear();
    }
    return 0;
}
