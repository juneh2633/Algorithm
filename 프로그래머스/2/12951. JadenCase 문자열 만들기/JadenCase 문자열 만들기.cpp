#include <bits/stdc++.h>
using namespace std;

using namespace std;

// '0'48
// 'A'65
// 'a'97

string solution(string s) {
    string answer = "";
    bool flag=1;
    for(auto &c:s){
        if(c==' '){
            flag=1;
            answer.push_back(' ');
            continue;
        }
        if(flag==1){
            if(c-'a'>=0){
                answer.push_back((char)(c-32));
            }else{
                answer.push_back(c);
            }
            flag=0;
        }else{
            if(c-'A'>=0&&c-'a'<0){
                answer.push_back((char)(c+32));
            }else{
                answer.push_back(c);   
            }
        }
    }
    return answer;
}