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
int xy[21][21];
int save[21][21];
bool visited[21][21];
int n;
void moveU(){
	FOR(i,n){
		for(int j=1;j<n;j++){
			if(xy[i][j]==0)continue;
			else{
				int t=1;
				while(j-t>0&&xy[i][j-t]==0){
					t++;
				}
				if(visited[i][j-t]==0&&xy[i][j]==xy[i][j-t]){
					xy[i][j-t]*=2;
					xy[i][j]=0;
					visited[i][j-t]=1;
					}
				else if(xy[i][j-t]==0){
					xy[i][j-t]=xy[i][j];
					xy[i][j]=0;
					}
				else{
					xy[i][j-t+1]=xy[i][j];
					if(t!=1)xy[i][j]=0;
					}
			}		
		}
	}	

}

void moveD(){
	FOR(i,n){
		for(int j=n-2;j>=0;j--){
			if(xy[i][j]==0)continue;
			else{
				int t=1;
				while(j+t<n-1&&xy[i][j+t]==0){
					t++;
				}
				if(visited[i][j+t]==0&&xy[i][j]==xy[i][j+t]){
					xy[i][j+t]*=2;
					xy[i][j]=0;									visited[i][j+t]=1;
					}
				else if(xy[i][j+t]==0){
					xy[i][j+t]=xy[i][j];
					xy[i][j]=0;
					}
				else{
					xy[i][j+t-1]=xy[i][j];
					if(t!=1)xy[i][j]=0;
					}
			}		
		}
	}	
}

void moveL(){
	FOR(j,n){
		for(int i=1;i<n;i++){
			if(xy[i][j]==0)continue;
			else{
				int t=1;
				while(i-t>0&&xy[i-t][j]==0){
					t++;
				}
				if(visited[i-t][j]==0&&xy[i][j]==xy[i-t][j]){
					xy[i-t][j]*=2;
					xy[i][j]=0;
					visited[i-t][j]=1;	
					}
				else if(xy[i-t][j]==0){
					xy[i-t][j]=xy[i][j];
					xy[i][j]=0;
					}
				else{
					xy[i-t+1][j]=xy[i][j];
					if(t!=1)xy[i][j]=0;
					}
			}		
		}
	}	
}

void moveR(){
	FOR(j,n){
		for(int i=n-2;i>=0;i--){
			if(xy[i][j]==0)continue;
			else{
				int t=1;
				while(i+t<n-1&&xy[i+t][j]==0){
					t++;
				}
				if(visited[i+t][j]==0&&xy[i][j]==xy[i+t][j]){
					xy[i+t][j]*=2;
					xy[i][j]=0;
					visited[i+t][j]=1;	
					}
				else if(xy[i+t][j]==0){
					xy[i+t][j]=xy[i][j];
					xy[i][j]=0;
					}
				else{
					xy[i+t-1][j]=xy[i][j];
					if(t!=1)xy[i][j]=0;
					}
			}		
		}
	}	

}
void On(int i){
	memset(visited,0,sizeof(visited));
	if(i==0)moveU();
	else if(i==1)moveD();
	else if(i==2)moveL();
	else moveR();
	return;
}
int ans=0;
void Ans(int a,int b,int c,int d,int e){
	On(a);
	On(b);
	On(c);
	On(d);
	On(e);
	FOR(j,n)FOR(i,n){
		ans=max(ans,xy[i][j]);
		xy[i][j]=save[i][j];
	}
	
}
int num[5];
void BF(int tmp){
	if(tmp==5){
		Ans(num[0],num[1],num[2],num[3],num[4]);
		return;	
	}
	FOR(i,4){
		num[tmp]=i;
		BF(tmp+1);
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	FOR(j,n)FOR(i,n){
		cin>>xy[i][j];
		save[i][j]=xy[i][j];
			}
	BF(0);
	cout<<ans;

}	