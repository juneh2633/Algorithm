#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <queue>
#include <map>
#define FOR(i,j) for(int i=0; i< (j);i++)
using namespace std;


int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  int n;
  int dp[1111]={1,};
  int arr[1111]={0,};
  cin>>n;
  int ans=0;
  FOR(i,n)cin>>arr[i];
  FOR(i,n){
      dp[i]=1;
    FOR(j,i){
      if(arr[i]>arr[j])dp[i]=max(dp[i],dp[j]+1);
    }
    ans=max(dp[i],ans);
  }
  cout<<ans;
  }