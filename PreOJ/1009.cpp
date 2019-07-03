//
//  main.cpp
//  1009
//
//  Created by Luke Alpha on 2019/7/3.
//  Copyright © 2019 lukealpha. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
    int n,x;
    queue<int> values;
    scanf("%d%d",&n,&x);
    for (int i = 1; i <= n; i ++) {
        int tmp;
        scanf("%d",&tmp);
        if(tmp!=x) values.push(tmp);
    }
    while (!values.empty()) {
        printf("%d ",values.front());
        values.pop();
    }
    return 0;
}
