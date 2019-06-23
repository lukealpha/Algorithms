#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <map>
#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;
map<string,int> used;
struct Node{
    int x,y,value;
    int graph[4][4];
    int step;

};
bool operator< (Node a, Node b){
    return a.value > b.value;
}
string make_route(Node x){
    string returnValue;
    for(int i = 1; i <= 3; i ++){
        for (int j = 1; j <= 3; j ++) {
            returnValue += x.graph[i][j] + '0';
        }
    }
    //cout<<returnValue<<endl;;
    return returnValue;
}
int H(Node x){
    int ans = 0;
    int tx[10]={2,1,1,1,2,3,3,3,2};
    int ty[10]={2,1,2,3,3,3,2,1,1};
    for(int i = 1; i <= 3; i ++){
        for(int j = 1;j <= 3; j ++){
            ans += abs(i-tx[x.graph[i][j]]);
            ans += abs(j-ty[x.graph[i][j]]);
        }
    }
    return ans;
}
Node input;
int togo[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
priority_queue<Node> statusTree;
int bfs(){
    statusTree.push(input);
    while(!statusTree.empty()){
        Node now = statusTree.top();
        if(make_route(now) == "123804765"){
            return now.step;
        }
        statusTree.pop();
        int nx,ny;
        for(int i = 0; i <= 3; i ++){
            nx = now.x + togo[i][0];
            ny = now.y + togo[i][1];
            if(nx >= 1 && ny >= 1 && nx <= 3 && ny <= 3){
                Node next = now;
                next.x = nx;
                next.y = ny;
                next.step ++;
                //swap(next.graph[now.x][now.y],next.graph[next.x][next.y]);
                next.graph[now.x][now.y] = next.graph[next.x][next.y];
                next.graph[next.x][next.y] = 0;
                next.value = H(next)+next.step;
                if(!used[make_route(next)]){
                    statusTree.push(next);
                    used[make_route(next)] = true;
                }
            }
        }
    }
    return -1;
}
int main(){
    string ino;
    cin>>ino;
    int cnt = 0;
    input.step = 0;
    for(int i = 1; i <= 3; i ++){
        for(int j = 1; j <= 3; j ++){
            input.graph[i][j] = ino[cnt++]-'0';
            if(!input.graph[i][j]){
                input.x = i;
                input.y = j;
            }
        }
    }
    input.value = input.step + H(input);
    printf("%d",bfs());
    return 0;
}
