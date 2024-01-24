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
        ll ans = 0;
        int n, k;
        cin >> n;
        vector<int> v(n);
        for (auto& i : v) cin >> i;
        cin >> k;

        priority_queue<pii, vii, greater<pii>> pq;
        pq.push({0, k});
        while (pq.top().second) {
            pii tmp = pq.top();
            pq.pop();
            pq.push({tmp.first + tmp.second, 0});
            for (auto& i : v) {
                pq.push({tmp.first + tmp.second % i, tmp.second / i});
            }
        }
        cout << "#" << t << " " << pq.top().first << '\n';
    }
    return 0;
}
