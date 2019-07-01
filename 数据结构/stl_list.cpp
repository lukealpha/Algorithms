//
//  main.cpp
//  stl_list
//
//  Created by Luke Alpha on 2019/6/30.
//  Copyright © 2019 lukealpha. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <list>
using namespace std;
//list<int> li;


int main(int argc, const char * argv[]) {
    int a[5] = {0,1,2,3,4};
    list<int> li(a, a + 4 + 1);
    list<int>::iterator it = li.begin();
    it ++; it ++;
    li.insert(it, 14);
    for (list<int>::iterator iter = li.begin(); iter != li.end(); iter ++) {
        printf("%d ",*iter);
    }
    
    return 0;
}
