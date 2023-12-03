#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstring>
#include <deque>
#include <stack>
#include <iomanip>
#include <queue>
#include <utility>
#include <map>
#include <math.h>
using namespace std;
typedef long long ll;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    ll b[101]={0,};
    ll c[101]={0,};
    ll dp[101][10002];
    for(ll i=1;i<=n;i++){
        cin>>b[i];
    }
    for(ll i=1;i<=n;i++){
        cin>>c[i];
    }

    ll ans=1000000000;
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<=10000;j++){
            if(j-c[i]>=0){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-c[i]]+b[i]);
            }
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
            if(dp[i][j]>=m){
                ans=min(ans,j);
            }

        }



    }

    cout<<ans;
}