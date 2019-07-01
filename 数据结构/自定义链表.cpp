
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
void insert(int loc,int val){
    node[++tot].val = val;
    
    node[node[loc].next].prev = tot;
    node[tot].next =  node[loc].next;
    node[loc].next = tot;
    node[tot].prev = loc;
    
}
int find_val(int value){
    for(int i = node[head].next; i != tail; i = node[i].next ){
        if(node[i].val == value){
            return i;
        }
    }
    return -1;
}
void erase(int p){
    node[node[p].prev].next = node[p].next;
    node[node[p].next].prev = node[p].prev;
}
int main() {
    initialize();
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++) {
        string command;
        cin>>command;
        if(command == "insert"){
            int value;
            scanf("%d",&value);
            insert(head,value);
        }
        if(command == "delete"){
            int value;
            scanf("%d",&value);
            erase(find_val(value));
        }
        if(command == "deleteFirst"){
            erase(node[head].next);
        }
        if(command == "deleteLast"){
            erase(node[tail].prev);
        }
    }
    for(int i = node[head].next; i != tail; i = node[i].next){
        printf("%d ",node[i].val);
    }
    return 0;
}
