#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    int answer = nums.size()/2;
    
    map<int,int>mp;
    for(auto &i:nums){
        mp[i]++;
    }
    
    return mp.size()>answer?answer:mp.size();
}