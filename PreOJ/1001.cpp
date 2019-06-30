//
//  main.cpp
//  1001
//
//  Created by Luke Alpha on 2019/6/30.
//  Copyright © 2019 lukealpha. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int lucky[15] = {0,4,7,47,74,44,77,444,447,474,477,744,747,774,777};

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= 14; i++) {
        if(n%lucky[i] == 0){
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}
