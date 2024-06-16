#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
ll n, m;

ll di[2] = {1, 0};
ll dj[2] = {0, 1};
ll dp[111][111];
ll wall[111][111][2];

bool inRange(ll i, ll j) {
    if (i < 0 || i > n) {
        return false;
    }
    if (j < 0 || j > m) {
        return false;
    }
    return true;
}
ll solution(ll i, ll j) {
    if (i == n && j == m) {
        return 1;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    dp[i][j] = 0;
    for (int d = 0; d < 2; d++) {
        if (wall[i][j][d]) {
            continue;
        }

        ll ii = i + di[d];
        ll jj = j + dj[d];
        if (!inRange(ii, jj)) {
            continue;
        }
        dp[i][j] += solution(ii, jj);
    }
    return dp[i][j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    ll k;
    cin >> k;
    memset(dp, -1, sizeof(dp));
    while (k--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a > c) {
            swap(a, c);
        }
        if (b > d) {
            swap(b, d);
        }
        if (c - a) {
            wall[a][b][0] = 1;
        } else {
            wall[a][b][1] = 1;
        }
    }
    cout << solution(0, 0);
}