
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 4
#define N2 16
using namespace std;
int mdTable[N2][N2];
struct graph{
    int space,steps;
    int md_value;
    int G[N2];
    bool operator < (const graph &p)const{
        for(int i = 9; i < N2; i ++){
            if(G[i] == p.G[i]){
                continue;
            }
            return G[i] < p.G[i];
        }
        return false;
    }
};
struct status{
    graph Graph;
    int E;
    bool operator < (const status &p)const{
        return E < p.E;
    }
};
int getMDSum(graph x){
    for(int i = 1; i <= n; i ++){
        
    }
    
}
int main(int argc, const char * argv[]) {
    for(int i = 0; i < N2; i ++){
        for (int j = 0; j < N2; j++) {
            mdTable[i][j] = abs(i / N - j / N) + abs(i % N - j % N);
        }
    }
    return 0;
}






0 0 0 0 0 1 1 1 0 0 0
0 0 0 1 1 0 0 1 0 0 1
1 0 1 1 0 0 1 1 0 0 0
1 0 0 0 1 1 0 0 0 1 0
0 0 1 1 0 0 0 0 1 0 1
