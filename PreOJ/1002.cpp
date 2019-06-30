//
//  main.cpp
//  1002
//
//  Created by Luke Alpha on 2019/6/30.
//  Copyright © 2019 lukealpha. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int apple[11];
int main() {
    for (int i = 1; i <= 10; i ++) {
        scanf("%d",&apple[i]);
    }
    int maximum;
    scanf("%d",&maximum);
    maximum += 30;
    int ans = 0;
    for (int i = 1; i <= 10; i ++) {
        if(apple[i] <= maximum) ans ++;
    }
    printf("%d",ans);
    return 0;
}
