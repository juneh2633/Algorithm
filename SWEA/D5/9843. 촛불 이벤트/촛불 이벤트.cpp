#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T;
    cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll n;
        cin >> n;
        ll ans = -1;
        ll sq = sqrt(2 * n);
        if (sq * (sq + 1) / 2 == n) ans = sq;
        cout << "#" << t << " " << ans << '\n';
    }
    return 0;
}
