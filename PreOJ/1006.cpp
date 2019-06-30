//
//  main.cpp
//  1006
//
//  Created by Luke Alpha on 2019/6/30.
//  Copyright © 2019 lukealpha. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int que[201];
int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d",&que[i]);
    }
    int x;
    scanf("%d",&x);
    for (int i = 1; i <= n; i ++) {
        if(i == x){ printf("%d ",que[n]);}
        else if(i > x) printf("%d ",que[i - 1]);
        else
        printf("%d ",que[i]);
    }
    return 0;
}
