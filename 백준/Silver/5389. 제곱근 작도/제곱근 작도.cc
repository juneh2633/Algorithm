#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solution() {
    ll n;
    cin >> n;
    vector<pii> ans;
    for (ll y = 1; y * y <= n; y++) {
        if (n % y) {
            continue;
        }
        ll x = n / y;

        if ((x + y) % 2 || x < y) {
            continue;
        }

        // cout << (x - y) / 2 << " " << (x + y) / 2 << '\n';
        ans.push_back({(x - y) / 2, (x + y) / 2});
    }
    if (ans.empty()) {
        cout << "IMPOSSIBLE";
        return;
    }
    sort(ans.begin(), ans.end());
    cout << ans[0].first << " " << ans[0].second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << '\n';
    }
}