//
//  main.cpp
//  1004
//
//  Created by Luke Alpha on 2019/6/30.
//  Copyright © 2019 lukealpha. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int height[10010];
int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    float sum = 0;
    for(int i =1; i <= n; i ++){
        scanf("%d",&height[i]);
        sum += height[i];
    }
    sum = sum / n;
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        if(height[i] > sum) ans ++;
    }
    printf("%d",ans);
}
