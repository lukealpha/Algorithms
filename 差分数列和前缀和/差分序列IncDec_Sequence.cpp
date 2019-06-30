#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int sequence[100010];
int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i ++){
        scanf("%d",&sequence[i]);
    }
    for(int i = 2; i <= n; i ++){
        sequence[i] = sequence[i] - sequence[i - 1];
    }
    int pos,neg;
    for(int i = 2; i <= n; i ++){
        if(sequence[i] > 0) pos += sequence[i];
        if(sequence[i] < 0) neg += abs(sequence[i]);
    }
    printf("%d\n%d",max(pos,neg),abs(pos-neg) + 1);
    return 0;
}
