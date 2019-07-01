//
//  main.cpp
//  1007
//
//  Created by Luke Alpha on 2019/6/30.
//  Copyright © 2019 lukealpha. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int list[1010];
int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d",&list[i]);
    }
    int x;
    scanf("%d",&x);
    for (int i = 1; i <= n; i ++) {
        if(i == x)
            continue;
        printf("%d ",list[i]);
    }
    return 0;
}
