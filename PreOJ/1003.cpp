//
//  main.cpp
//  1003
//
//  Created by Luke Alpha on 2019/6/30.
//  Copyright © 2019 lukealpha. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
bool trees[10000];
int main(int argc, const char * argv[]) {
    int L,m;
    scanf("%d%d",&L,&m);
    for(int i = 1; i <= m; i ++){
        int x,y;
        scanf("%d%d",&x,&y);
        for (int j = x; j <= y; j ++) {
            if(!trees[j]) {trees[j] = true; L--;}
        }
    }
    printf("%d",L + 1);
    return 0;
}
