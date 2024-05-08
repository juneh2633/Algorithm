#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MAX = 111111111;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n;
    int dp[22][2];
    vector<pii> v(n);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }
    cin >> k;
    for (int i = 0; i <= n; i++) {
        dp[i][0] = MAX;
        dp[i][1] = MAX;
    }
    dp[1][0] = 0;
    dp[2][0] = v[1].first;
    dp[3][0] = min(v[1].first + v[2].first, v[1].second);
    for (int i = 4; i <= n; i++) {
        dp[i][0] =
            min(v[i - 1].first + dp[i - 1][0], v[i - 2].second + dp[i - 2][0]);
        dp[i][1] = min(
            min(v[i - 1].first + dp[i - 1][1], v[i - 2].second + dp[i - 2][1]),
            k + dp[i - 3][0]);
    }
    cout << min(dp[n][0], dp[n][1]);
}