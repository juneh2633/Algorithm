#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#define FOR(i,j) for(int i=0; i< (j);i++)
using namespace std;


int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,k;
  int ans=0;
  cin>>n>>k;
  int A[1111111]={0};
  FOR(i,n)cin>>A[i];
  while(k!=0){
    ans=ans+k/A[n-1];
    k=k%A[n-1];

    n--;
  }
  cout<<ans;
}