
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct Node{
    int val;
    int next,prev;
}node[500010];
int head,tail,tot;
void initialize(){
    tot = 2;
    head = 1;
    tail = 2;
    node[head].next = tail;
    node[tail].prev = head;
}
int curve;
void move(int step){
    for(int i = 1; i <= abs(step); i ++){
        if(step < 0) curve = node[curve].prev;
        if(step > 0) curve = node[curve].next;
    }
}
void insert(int loc,int val){
    node[++tot].val = val;
    
    node[node[loc].prev].next = tot;
    node[tot].prev = node[loc].prev;
    node[loc].prev = tot;
    node[tot].next = loc;
    
}
void erase(int p){
    node[node[p].prev].next = node[p].next;
    node[node[p].next].prev = node[p].prev;
}
int main() {
    initialize();
    curve = tail;
    int n;
    scanf("%d",&n);
    for(int i =1; i <= n; i ++){
        int command;
        scanf("%d",&command);
        if(command == 0) {int value;
            scanf("%d",&value);
            insert(curve, value);
            move(-1);
        }
        else if(command == 1){
            int value;
            scanf("%d",&value);
            move(value);
        }
        else if(command == 2){
            erase(curve);
            move(1);
        }
        printf("%d\n",curve);
        
    }
    cout<<endl;
//    for(int i = node[head].next; i != tail; i = node[i].next){
//        printf("%d\n",node[i].val);
//    }
    return 0;
}
