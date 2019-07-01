//
//  main.cpp
//  循环调度程序
//
//  Created by Luke Alpha on 2019/6/30.
//  Copyright © 2019 lukealpha. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct tasks{
    int time;
    string name;
    
};
queue<tasks> q;


int main(int argc, const char * argv[]) {
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i ++) {
        string s;
        int x_time;
        cin>>s;
        scanf("%d",&x_time);
        q.push(tasks{x_time,s});
        
    }
    int timer = 0;
    while(!q.empty()){
        tasks current = q.front();
        q.pop();
        timer += min(m,current.time);
        if(current.time <= m){
            printf("%s ",current.name.c_str());
            printf("%d\n",timer);
        }
        else if(current.time > m){
            q.push(tasks{current.time - m, current.name});
        }
    }
    return 0;
}
