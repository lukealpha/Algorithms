//
//  main.cpp
//  1005
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
    int max_height = 0;
    int ans_loc = 0;
    for (int i = 1; i <= n; i ++) {
        scanf("%d",&height[i]);
        if(height[i] > max_height) {max_height = height[i]; ans_loc = i;}
    }
    swap(height[1], height[ans_loc]);
    for (int i = 1; i <= n; i ++) {
        printf("%d ",height[i]);
    }
    return 0;
}
