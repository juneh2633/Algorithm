#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#define FOR(i,j) for(int i=0; i< (j);i++)
using namespace std;

int main(){
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

int N, A[111]={0},B[111]={0};
cin>>N;
FOR(i,N)cin>>A[i];
FOR(j,N)cin>>B[j];
sort(A,A+N);
sort(B,B+N,greater<int>());
int ans=0;
FOR(x,N)ans=ans+A[x]*B[x];
cout <<ans;
}