#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int s[100010];
bool bfind(int target){
    int l = 1,r = n + 1;
    bool flag = false;
    while(l < r){
        int mid = (l + r) / 2;
        if(target <= s[mid]) r = mid; else l = mid + 1;
        if (s[mid] == target) flag = true;
    }
    return flag;
}
int main(int argc, const char * argv[]) {

    scanf("%d",&n);
    for(int i = 1; i <= n; i ++){
        scanf("%d",&s[i]);
    }
    int q;
    scanf("%d",&q);
    int ans = 0;
    for (int i = 1; i <= q; i ++) {
        int target_value;
        scanf("%d",&target_value);
        if(bfind(target_value)){
            ans ++;
        }
    
    }
    printf("%d",ans);
    return 0;
}
