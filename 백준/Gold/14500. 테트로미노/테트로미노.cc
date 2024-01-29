#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <queue>
#include <utility>
#include <map>
#define FOR(i,j) for(int i=0; i< (j);i++)
typedef long long ll;
using namespace std;
int n,m;
int xy[501][501];
int ans=0;
bool visited[501][501]={false,};
void dfs(int x, int y,int cnt,int sum){
  visited[x][y]=true;
  if(cnt==3){
    
    ans=max(ans,sum);
    return;
  }
  if(x+1<m&&visited[x+1][y]==false){
    dfs(x+1,y,cnt+1,sum+xy[x+1][y]);  
    visited[x+1][y]=false;
  }
  if(y+1<n&&visited[x][y+1]==false){
    dfs(x,y+1,cnt+1,sum+xy[x][y+1]);
    visited[x][y+1]=false;
  }
  if(x-1>=0&&visited[x-1][y]==false){
    dfs(x-1,y,cnt+1,sum+xy[x-1][y]);  
    visited[x-1][y]=false;
  }
  if(y-1>=0&&visited[x][y-1]==false){
    dfs(x,y-1,cnt+1,sum+xy[x][y-1]);
    visited[x][y-1]=false;
  }



}
void T(int x,int y){
  if(y+2<n&&x+1<m)ans=max(ans,xy[x][y]+xy[x][y+1]+xy[x][y+2]+xy[x+1][y+1]);
  if(y+2<n&&x-1>=0)ans=max(ans,xy[x][y]+xy[x][y+1]+xy[x][y+2]+xy[x-1][y+1]);

  if(x+2<m&&y+1<n)ans=max(ans,xy[x][y]+xy[x+1][y]+xy[x+2][y]+xy[x+1][y+1]);
  if(x+2<m&&y-1>=0)ans=max(ans,xy[x][y]+xy[x+1][y]+xy[x+2][y]+xy[x+1][y-1]);

  if(y-2>=0&&x+1<m)ans=max(ans,xy[x][y]+xy[x][y-1]+xy[x][y-2]+xy[x+1][y-1]);
  if(y-2>=0&&x-1>=0)ans=max(ans,xy[x][y]+xy[x][y-1]+xy[x][y-2]+xy[x+-1][y-1]);

  if(x-2>=0&&y+1<n)ans=max(ans,xy[x][y]+xy[x-1][y]+xy[x-2][y]+xy[x-1][y+1]);
  if(x-2>=0&&y-1>=0)ans=max(ans,xy[x][y]+xy[x-1][y]+xy[x-2][y]+xy[x-1][y-1]);
  return;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  cin>>n>>m;
  FOR(j,n)FOR(i,m)cin>>xy[i][j];
  FOR(j,n)FOR(i,m){
    memset(visited,0,sizeof(visited));
    dfs(i,j,0,xy[i][j]);
    T(i,j);
    }
  cout<<ans;
}