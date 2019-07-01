//
//  main.cpp
//  最大装载(二分)
//
//  Created by Luke Alpha on 2019/7/1.
//  Copyright © 2019 lukealpha. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 100010
using namespace std;
int weight[maxn];
int n,k;
int verify(int p){
    int did = 1;
    for(int i = 1; i <= k; i ++){
        int s = 0;
        while(s + weight[did] <= p){
            s += weight[did];
            did++;
            if(did == n + 1) return n;
        }
    }
    return did - 1;
}
//bool cmp(int a,int b) {return a > b;}
int main(int argc, const char * argv[]) {
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i ++) {
        scanf("%d",&weight[i]);
        //sum += weight[i];
    }
    //sort(weight + 1, weight + n + 1,cmp);
    int l = 0,r = 1000000000;
    //int last_ans = 0;
    while(l < r){
        int mid = (l + r) / 2;
        //printf("%d ",mid);
        if(verify(mid) >= n) {
            r = mid;
        }
        else l = mid + 1;
    }
    printf("%d",l);
    return 0;
}

