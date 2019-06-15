#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <map>
#include <math.h>
#include <string.h>
using namespace std;
map<string,int> used;
struct Node{
    int x,y,value;
    int graph[5][5];
    int step = 0;
    
};
bool operator< (Node a, Node b){
    return a.value > b.value;
}
char hexx[20] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G'};
string make_route(Node x){
    string returnValue;
    for(int i = 1; i <= 4; i ++){
        for (int j = 1; j <= 4; j ++) {
            
            returnValue += hexx[x.graph[i][j]];
        }
    }
    //cout<<returnValue<<endl;;
    return returnValue;
}
int H(Node x){
    int ans = 0;
    int tx[20]={4,1,1,1,1,2,2,2,2,3,3,3,3,4,4,4};
    int ty[20]={4,1,2,3,4,1,2,3,4,1,2,3,4,1,2,3};
    for(int i = 1; i <= 4; i ++){
        for(int j = 1;j <= 4; j ++){
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
        if(make_route(now) == "123456789ABCDEF0"){
            return now.step;
        }
        //cout<<make_route(now);
        
        statusTree.pop();
        int nx,ny;
        for(int i = 0; i <= 4; i ++){
            nx = now.x + togo[i][0];
            ny = now.y + togo[i][1];
            if(nx >= 1 && ny >= 1 && nx <= 4 && ny <= 4){
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
    input.step = 0;
    for(int i = 1; i <= 4; i ++){
        for(int j = 1; j <= 4; j ++){
            scanf("%d",&input.graph[i][j]);
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
