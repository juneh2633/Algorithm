#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    ll n;
    string s;
    cin>>n>>s;
    vector<ll>v;
    ll tmp=0;
    if(n==1){
        cin>>n;
        cout<<0;
        return 0;
    }
    for(ll i=0;i<n;i++){
        ll x;

        cin>>x;
        if(i==0)continue;

        if(s[i]==s[i-1]){
            if(tmp==0)tmp=x;
            if(tmp<x)tmp=x;
            if(i==n-1){
                v.push_back(tmp);
            }
        }
        else{
            v.push_back(tmp);
            tmp=x;
            if(i==n-1){
                v.push_back(tmp);
            }
        }
    }
    if(!v.empty())v.erase(v.begin());
    if(!v.empty())v.erase(v.end()-1);
    if(v.empty()){
        cout<<0;
        return 0;
    }
                                    // for(ll i=0;i<v.size();i++){
                                    //     cout<<v[i]<<" ";
                                    // }
                                    // cout<<'\n'<<"@@@@@@@@"<<'\n';
    sort(v.rbegin(),v.rend());

    //                                 for(ll i=0;i<v.size();i++){
    //                                     cout<<v[i]<<" ";
    //                                 }

    //                                 cout<<'\n';
    ll ans=0;
    ll t=v.size()/2;
    if(v.size()%2==1)t++;
    for(ll i=0;i<t;i++){
        ans+=v[i];
    }
    cout<<ans;
    

}