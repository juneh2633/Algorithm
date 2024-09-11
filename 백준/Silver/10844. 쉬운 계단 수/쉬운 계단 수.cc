#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll MOD = 1e9;
ll a;
ll ans = 0;
ll d[111][111];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a;
    memset(d, 0, sizeof(d));
    for (int i = 0; i < 10; i++) {
        d[0][i] = 1;
    }

    for (int i = 1; i < a; i++) {
        for (int j = 1; j < 9; j++) {
            d[i][j] += d[i - 1][j - 1] % MOD;
            d[i][j] += d[i - 1][j + 1] % MOD;
        }
        d[i][0] += d[i - 1][1] % MOD;
        d[i][9] += d[i - 1][8] % MOD;
    }

    for (int i = 1; i < 10; i++) {
        ans += d[a - 1][i] % MOD;
    }
    cout << ans % MOD;
}
