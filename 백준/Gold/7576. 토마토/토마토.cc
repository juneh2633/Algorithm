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
int m,n;
queue<pair<int,int>>q;
int v[1111][1111]={0,};
int dx[4]={1,-1,0,0,};
int dy[4]={0,0,1,-1};
void bfs(){

  while(!q.empty()){
    int x=q.front().first;
    int y=q.front().second;
    q.pop();
    FOR(t,4){
      int nx=dx[t]+x;
      int ny=dy[t]+y;
      if(nx>=m||nx<0||ny>=n||ny<0)continue;
      if(v[nx][ny]==0){
        v[nx][ny]=v[x][y]+1;
        q.push({nx,ny});
      }
    }

  }



}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  cin>>m>>n;
  bool flag=0;
  FOR(j,n)FOR(i,m){

    cin>>v[i][j];
    if(v[i][j]==1)q.push({i,j});
    if(v[i][j]==0)flag=1;
  }
  if(flag==0){
    cout<<'0';
    return 0;
    }
  bfs();

  int mx=0;
  FOR(j,n)FOR(i,m){
    if(v[i][j]==0){
      cout<<"-1";
      return 0;
    }
  mx=max(mx,v[i][j]);
  }
  cout<<mx-1;

}