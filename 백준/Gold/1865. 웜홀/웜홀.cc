#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct road{
  int s,e,t;
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int tc;
  cin>>tc;
  while(tc--){
    int n,m,w;
    cin>>n>>m>>w;
    vector<road>v;
    vector<int>d(n+1,9999999);
    d[0]=0;
    for(int i=0;i<m;i++){
      int s,e,t;
      cin>>s>>e>>t;
      road r={s,e,t};
      road rr={e,s,t};
      v.push_back(r);
      v.push_back(rr);
    }
    for(int i=0;i<w;i++){
      int s,e,t;
      cin>>s>>e>>t;
      road r={s,e,t*(-1)};
      v.push_back(r);
    }
    bool check=0;
    
    for(int i=0;i<n;i++){
      for(int j=0;j<v.size();j++){
        int s = v[j].s;
        int e = v[j].e;
        int t = v[j].t;
        if(d[s] + t < d[e])d[e] = d[s]+ t;
      }
    }
    for(int j=0;j<v.size();j++){
      int s = v[j].s;
      int e = v[j].e;
      int t = v[j].t;
      if(d[s] + t < d[e]){
        check=1;
        break;
      }
    }
    if(check==1){
      cout<<"YES"<<'\n';
    }
    else cout<<"NO"<<'\n';
    v.clear();
  }
}