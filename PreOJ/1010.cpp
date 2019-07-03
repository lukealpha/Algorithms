//
//  main.cpp
//  1010
//
//  Created by Luke Alpha on 2019/7/3.
//  Copyright © 2019 lukealpha. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
int num[10010];
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++) {
        int tmp;
        scanf("%d",&tmp);
        num[tmp] = i;
    }
    int x;
    scanf("%d",&x);
    if(num[x] != 0) printf("%d",num[x]);
    else printf("0");
    return 0;
}
