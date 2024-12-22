#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;

ll solution(ll n) {
    ll dp[65][10] = {
        0,
    };
    ll sum = 0;
    for (ll i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }

    for (ll i = 2; i <= n; i++) {
        for (ll j = 0; j < 10; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] += dp[i - 1][k];
            }
        }
    }

    for (ll i = 0; i < 10; i++) {
        sum += dp[n][i];
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        ll a;
        cin >> a;
        cout << solution(a) << '\n';
    }
}