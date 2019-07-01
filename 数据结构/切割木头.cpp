#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n,k;
int wood[100010];
int check(int len){
    int ans = 0;
    for(int i = 1; i <= n; i ++){
        if(wood[i] > len)
        ans += wood[i] / len;
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    scanf("%d%d",&n,&k);
    int max_amount = 0;
    for (int i = 1; i <= n; i ++) {
        scanf("%d",&wood[i]);
        max_amount = max(max_amount,wood[i]);
    }
    int l = 1,r = max_amount;
    while(l < r){
        int mid = (l + r) >> 1;
        if(check(mid) >= k) l = mid + 1;
        else r = mid;
    }
    printf("%d",l - 1);
    return 0;
}
