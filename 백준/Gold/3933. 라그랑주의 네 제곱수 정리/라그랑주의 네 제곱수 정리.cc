#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
int dp[32888]={0,};

void sol(int dpth, int num,int ii){
    if(num>32888)return;
    if(dpth==4)return;
    for(int i=ii;i<183;i++){
        if(num+i*i>32888)return;
        dp[num+i*i]++;
        sol(dpth+1,num+i*i,i);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    sol(0,0,1);
    while(1){
        cin>>n;
        if(n==0)break;
        cout<<dp[n]<<'\n';

    }
 
}