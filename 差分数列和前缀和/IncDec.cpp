#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long sequence[100010];
int main(int argc, const char * argv[]) {
    //freopen("test.in","r",stdin);
    //freopen("test.out", "w", stdout);
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i ++){
        scanf("%lld",&sequence[i]);
    }
    for(int i = n; i >= 2 ; i --){
        sequence[i] = sequence[i] - sequence[i - 1];
    }
    long long pos,neg;
    pos = neg = 0;
    for(int i = 2; i <= n; i ++){
        if(sequence[i] > 0) pos += sequence[i];
        if(sequence[i] < 0) neg += abs(sequence[i]);
        //printf("%d ",sequence[i]);
    }
    long long maxi;
    if(pos > neg) maxi = pos;
    else maxi = neg;
    printf("%lld\n%lld",maxi,abs(pos-neg) + 1);
    return 0;
}
//1 1 2 2
//1 0 1 0
//3 2  5 1  6
//3 -1 3 -4 5
//
//5 8
//
