#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <queue>
#include <utility>
#include <set>
#define FOR(i,j) for(int i=0; i< (j);i++)
typedef long long ll;
using namespace std;
bool cp(int a,int b,int c,int d){
  if(a!=b)return false;
  if(a!=c)return false;
  if(a!=d)return false;
  if(b!=c)return false;
  if(b!=d)return false;
  if(c!=d)return false;
  return true;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  int n,m;
  cin>>n>>m;
  int ans=1;
  int xy[52][52];
  vector<pair<int,int>>cmp;
  FOR(j,n)FOR(i,m){
    char c;
    cin>>c;
    xy[i][j]=(int)c-48;
  }
  FOR(j,n){
    for(int a=0;a<m;a++){
      for(int b=a+1;b<m;b++){
        if(xy[a][j]==xy[b][j]){
          int d=b-a;
          if(j+d<n){
            if(cp(xy[a][j],xy[b][j],xy[a][j+d],xy[b][j+d])==true){
              ans=max((d+1)*(d+1),ans);
            }
          }

        }    
      }
    }


  }
  cout<<ans;
}