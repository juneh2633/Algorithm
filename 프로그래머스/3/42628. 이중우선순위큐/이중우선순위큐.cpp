#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    map<int,int>mp;
    for(auto &d: operations){
        if(d[0]=='I'){
            string numStr=d.substr(2,d.size()-2);
            int num = stoi(numStr);
            mp[num]++;
            continue;
        }else{
            if(d[2]=='1'&&!mp.empty()){
                auto it = --mp.end();
                if (it->second >= 2) {
                    it->second -= 1; 
                } else {
                    mp.erase(it); 
                }

            }
            if(d[2]!='1'&&!mp.empty()){
                auto it = mp.begin();
                if (it->second >= 2) {
                    it->second -= 1; 
                } else {
                    mp.erase(it); 
                }                
            }
        }
        
    }
    if(mp.size()==0){
        answer.push_back(0);
        answer.push_back(0);
    }else if(mp.size()==1){
        auto it = mp.begin();
        answer.push_back(it->first);
        answer.push_back(it->first);
    }else{
        auto it = --mp.end();
        answer.push_back(it->first);
        it = mp.begin();
        answer.push_back(it->first);
    }
    return answer;
}