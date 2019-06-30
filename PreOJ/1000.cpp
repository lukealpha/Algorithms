//
//  main.cpp
//  1000
//
//  Created by Luke Alpha on 2019/6/30.
//  Copyright © 2019 lukealpha. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int f[30];
int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    f[1] = 1;
    f[2] = 2;
    for(int i = 3; i <= n; i ++){
        f[i] = f[i - 1] + f[i - 2];
    }
    for(int i = 1; i <= n; i ++) printf("%d ",f[i]);
    return 0;
}
