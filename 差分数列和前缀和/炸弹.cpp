#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAX_B 5100
using namespace std;
int graph[MAX_B][MAX_B];
int prefix[MAX_B][MAX_B];
int main(){
    int n,r;
    //int max_bound = -1;
    scanf("%d%d",&n,&r);
    for(int i = 1; i <= n; i ++){
        int xi,yi,vi;
        scanf("%d%d%d",&xi,&yi,&vi);
        graph[xi][yi] = vi;
        if(xi == 0 || yi == 0){
            prefix[xi][yi] = vi;
        }
        //max_bound = max(max_bound,max(xi,yi));
    }
    
    //max_bound += r*2;
    for(int i = 0; i <= 5010; i ++){
        for(int j = 1; j <= 5010; j ++){
            prefix[i][j] = prefix[i][j-1] + graph[i][j];
        }
    }
    for(int i = 0; i <= 5010; i ++){
        for(int j = 1; j <= 5010; j ++){
            prefix[j][i] += prefix[j-1][i];
        }
    }
    //    for(int i = 0; i <= 5; i ++){
    //        for(int j = 0; j <= 5; j ++){
    //            printf("%d ",prefix[i][j]);
    //        }
    //        printf("\n");
    //    }
    int ans = -1;
    for(int i = r-1; i <= 5010; i ++){
        for(int j = r-1; j <= 5010; j ++){
            ans = max(ans,prefix[i][j] - prefix[i][j - r] - prefix[i - r][j] + prefix[i - r][j - r]);
        }
    }
    printf("%d",ans);
}
