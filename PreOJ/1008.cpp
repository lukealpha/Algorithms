//
//  main.cpp
//  1008
//
//  Created by Luke Alpha on 2019/6/30.
//  Copyright © 2019 lukealpha. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int list1[1010],list2[1010];
int main(int argc, const char * argv[]) {
    int n,m;
    scanf("%d%d",&n,&m);
    memset(list1, 0x3f, sizeof list1);
    memset(list2, 0x3f, sizeof list2);
    for (int i = 1; i <= n; i ++) {
        scanf("%d",&list1[i]);
    }
    for (int i = 1; i <= m; i ++) {
        scanf("%d",&list2[i]);
    }
    int t1,t2;
    t1 = t2 = 1;
    while(t1 <= n || t2 <= m){
        if(list1[t1] <= list2[t2]){
            printf("%d ",list1[t1]);
            t1 ++;
        }
        else {printf("%d ",list2[t2]);t2 ++;}
    }
    
    return 0;
}
