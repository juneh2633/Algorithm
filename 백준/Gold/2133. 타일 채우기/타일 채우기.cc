#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
ll dp[33] = {
    0,
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    dp[3] = 0;
    dp[4] = 9;
    ll n;
    cin >> n;
    if (n % 1 == 1) {
        cout << "0";
    }
    for (ll i = 4; i <= n; i++) {
        dp[i] = dp[i - 2] * dp[2];
        for (ll j = 4; j <= i; j = j + 2) {
            dp[i] = dp[i] + dp[i - j] * 2;
        }
    }
    cout << dp[n];
}
