#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
ll d=1000000007;
map<ll,ll>mp;
ll solution(ll n){
    if(n==0){
        return 0;
    }
    else if(n<=2){
        return 1;
    }
    if(mp.count(n)>0)return mp[n];
    if(n%2==0){
        ll s1=solution(n/2-1);
        ll s2=solution(n/2);
        ll r=2*s1+s2;
        r=r*s2;
        r=r%d;
        mp[n]=r;
        return r;
    }
    else{
        ll s1=solution(n/2+1);
        ll s2=solution(n/2);    
        ll r=s1*s1+s2*s2;
        mp[n]=r%d;
        return r%d;
    }

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
#ifndef ONLINE_JUDGE
     freopen("./input.txt", "r", stdin);
     freopen("./output.txt", "w", stdout);
#endif
    ll n;
    cin>>n;
    if(n==0){
        cout<<"0";
        return 0;
    }
    else if(n<=2){
        cout<<"1";
        return 0;        
    }

    cout<<solution(n);

}