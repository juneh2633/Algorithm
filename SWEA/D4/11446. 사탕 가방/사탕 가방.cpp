#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
const ll INF = 1000000000000000001;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T, n, m;
    cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll ans = 0;
        ll l = 1, r = 0;
        cin >> n >> m;
        vector<ll> v(n);
        for (auto &i : v) {
            cin >> i;
            if (r < i) {
                r = i;
            }
        }

        while (l <= r) {
            ll sum = 0;
            ll mid = l + (r - l) / 2;
            for (auto &i : v) {
                if (i >= mid) sum += i / mid;
            }
            if (sum >= m) {
                ans = mid;
                l = mid + 1;
            } else if (sum < m) {
                r = mid - 1;
            }
        }
        cout << "#" << t << " " << r << '\n';
    }
    return 0;
}

