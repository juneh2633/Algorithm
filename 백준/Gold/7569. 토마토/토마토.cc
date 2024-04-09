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
struct ppp{
    int y,x,z;
};
int day=0;

int m,n,h;
int yxz[111][111][111];
int visited[111][111][111]={0,};

int dy[6]={1,-1,0,0,0,0};
int dx[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};
queue<ppp>q;
bool check(int x,int y,int z){
  if(x<0||x>=m)return 0;
  if(y<0||y>=n)return 0;
  if(z<0||z>=h)return 0;

  return 1;
}
void bfs(){
    while(!q.empty()){
        ppp tmp=q.front();
        q.pop();
        for(int i=0;i<6;i++){
            int ddy=tmp.y+dy[i];
            int ddx=tmp.x+dx[i];
            int ddz=tmp.z+dz[i];
            if(!check(ddx,ddy,ddz))continue;
            if(visited[ddy][ddx][ddz]>=0)continue;
            visited[ddy][ddx][ddz]=visited[tmp.y][tmp.x][tmp.z]+1;
            q.push({ddy,ddx,ddz});
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>m>>n>>h;
    
    for(int k=0;k<h;k++){

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                cin>>yxz[i][j][k];
                if(yxz[i][j][k]==1){
                    q.push({i,j,k});
                }
                if(yxz[i][j][k]==0){
                    visited[i][j][k]=-1;
                }

            }
        }

    }
    bfs();
    for(int k=0;k<h;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j][k]==-1){
                    cout<<-1;
                    return 0;
                }
                day=max(day,visited[i][j][k]);                
            }
        }
    }    
    cout<<day;

}