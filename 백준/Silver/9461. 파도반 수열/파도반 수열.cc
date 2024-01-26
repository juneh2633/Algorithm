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
#include <set>
#define FOR(i,j) for(int i=0; i< (j);i++)
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  long long dp[111]={0,};
  int t;
  cin>>t;
  dp[1]=1;
  dp[2]=1;
  dp[3]=1;
  dp[4]=2;
  dp[5]=2;
  FOR(tc,t){
    int n;
    cin>>n;
    if(dp[n]!=0){
      cout<<dp[n]<<'\n';
      continue;
      }
    for(int i=6;i<=n;i++){
      dp[i]=dp[i-1]+dp[i-5];
    }
    cout<<dp[n]<<'\n';
  }

}