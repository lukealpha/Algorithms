//
//  main.cpp
//  逆波兰表达式
//
//  Created by Luke Alpha on 2019/6/30.
//  Copyright © 2019 lukealpha. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

stack<int> st;

int main(int argc, const char * argv[]) {
    string s;
    while(cin>>s){
        if(s == "+"){
            int a,b;
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(a+b);
        }
        else if(s == "-"){
            int a,b;
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(b-a);

        }
        else if(s == "*"){
            int a,b;
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(a*b);
        }
        else{
            st.push(atoi(s.c_str()));
        }
    }
    printf("%d",st.top());
    return 0;
}
