#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
ll mx=11111111111;

int main(){

  ios::sync_with_stdio(false); cin.tie(0);
  ll n,k;
  cin >> n >> k;
  ll i=1;
  ll r=0;
  while (i <= n) {
      ll q = k % i;
      ll p = k / i;
      ll a = (p > 0) ? q / p :mx;
      r  =r+ (2*q - p*min(a, n - i))*(min(a, n - i)+1)/2;
      i += min(a, n - i) + 1;
  }
  cout<<r;
}

