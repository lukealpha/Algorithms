#include <cstdio>
#include <algorithm>
#include <iostream>
#include <list>

using namespace std;
struct Node{
    int val;
    int number;
};
list<Node> nodes;
Node input[100010];
int source[100010];
Node ans[100010];
list<Node>::iterator tags[100010];
bool cmp(Node a, Node b){
    return a.val < b.val;
}
list<Node>::iterator find_val(int val){
    list<Node>::iterator it;
    for(it = nodes.begin();it != nodes.end();it ++){
        if(it->val == val)
            return it;
    }
    return it;
}
int main(int argc, const char * argv[]){
    list<Node>::iterator head = --nodes.begin();
    list<Node>::iterator tail = nodes.end();
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d",&input[i].val);
        input[i].number = i;
        source[i] = input[i].val;
    }
    sort(input + 1, input + n + 1,cmp);
    for (int i =1; i <= n; i ++) {
        nodes.push_back(input[i]);
        
    }
    for(list<Node>::iterator tmp = nodes.begin(); tmp != nodes.end(); ++tmp){
        tags[tmp->number] = tmp;
    }
    for(int i = n; i >= 1; i --){
        list<Node>::iterator loc = tags[i];
        list<Node>::iterator cur_iter = tags[i];
        Node current = *loc;
        loc -- ;
        Node last = Node{abs(loc->val - current.val),loc->number};
        if(loc == head)
            last.val = 0x3f3f3f3f;
        loc ++;loc ++;
        Node next = Node{abs(loc->val - current.val),loc->number};
        if(loc == tail)
            next.val = 0x3f3f3f3f;
        if(last.val > next.val){
            ans[i].val = next.val;
            ans[i].number = next.number;
        }
        if(last.val < next.val){
            ans[i].val = last.val;
            ans[i].number = last.number;
        }
        if(last.val == next.val){
            
            if(source[last.number] < source[next.number]){
                ans[i].val = last.val;
                ans[i].number = last.number;
            }
            else{
                ans[i].val = next.val;
                ans[i].number = next.number;
            }
        }
        nodes.erase(cur_iter);
    }
    for(int i = 2; i <= n; i ++){
        printf("%d %d\n",ans[i].val,ans[i].number);
    }
    return 0;
}
