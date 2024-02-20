#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <string>
#include <queue>
#define FOR(i,j) for(int i=0; i< (j);i++)
using namespace std;
int sq[224];
int n;
vector<int>v;
void squared(int k){
  FOR(i,k+1)sq[i]=i*i;
}

int solution(int sn){
  int ans=4;
  for(int a=sn;a>0;a--){
    int t=n;
    t-=sq[a];
    if(t==0)return 1;
    for(int b=sqrt(t);b>0;b--){
      int r=t;
      if(a<b)break;
      r-=sq[b];
      if(r==0)ans=min(ans,2);
      for(int c=sqrt(r);c>0;c--){
        int e=r;
        if(b<c)break;
        e-=sq[c];
        if(e==0)ans=min(ans,3);
        for(int d=sqrt(e);d>0;d--){
          int w=e;
          if(c<d)break;
          w-=sq[d];
          if(w==0)ans=min(ans,4);
          }
      }
    }
  }
  return ans;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  cin>>n;
  int ans=0;
  squared(sqrt(n));
  cout<<solution(sqrt(n));
} 
