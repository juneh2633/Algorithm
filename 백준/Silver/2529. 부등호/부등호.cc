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
typedef long long ll;
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n=0;
    cin>>n;
    bool bigger[10];

    char a;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a=='<')bigger[i]=1;
        else bigger[i]=0;

    }
    vector<int>v(10);
    vector<int>vR(10);
    vi ans(n+1);
    vi ansR(n+1);
    for(int i=0;i<=9;i++){
        v[i]=i;
        vR[9-i]=i;
    }

    do{
        bool check=1;
        for(int i=0;i<n;i++){
            if(bigger[i]==1){
                if(v[i]<v[i+1]){
                    check=1;
                }
                else{
                    check=0;
                    break;
                }
            }
            else{
                if(v[i]>v[i+1]){
                    check=1;
                }
                else{
                    check=0;
                    break;
                }                
            }
        }
        if(check==0){
            continue;
        }
        for(int i=0;i<=n;i++){
            ans[i]=v[i];
        }
        break;
    }
    while(next_permutation(v.begin(),v.end()));
    
    do{
        bool check=1;
        for(int i=0;i<n;i++){
            if(bigger[i]==1){
                if(vR[i]<vR[i+1]){
                    check=1;
                }
                else{
                    check=0;
                    break;
                }
            }
            else{
                if(vR[i]>vR[i+1]){
                    check=1;
                }
                else{
                    check=0;
                    break;
                }                
            }
        }
        if(check==0){
            continue;
        }
        for(int i=0;i<=n;i++){
            ansR[i]=vR[i];
        }
        break;
    }
    while(prev_permutation(vR.begin(),vR.end()));

    for(auto &it:ansR)cout<<it;
    cout<<'\n';
    for(auto &it:ans)cout<<it;
 
}