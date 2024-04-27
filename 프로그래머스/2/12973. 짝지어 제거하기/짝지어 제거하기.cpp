#include <bits/stdc++.h>
using namespace std;


int solution(string s){

    stack<char>st;
    for(auto &c : s){
        if(!st.empty()){
            char t = st.top();
            if(c == t){
                st.pop();
                continue;
            }
        }
        st.push(c);
    }

    return st.empty()?1:0;
}