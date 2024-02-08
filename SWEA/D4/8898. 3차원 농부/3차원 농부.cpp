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

    ll T, n, m, c1, c2;

    cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll l = 1, r = 0;

        cin >> n >> m >> c1 >> c2;
        vector<ll> cow(n);

        for (auto &i : cow) {
            cin >> i;
        }
        sort(cow.begin(), cow.end());
        int ans = 1111111111;
        int ans_cnt = 0;
        for (int i = 0; i < m; i++) {
            int horse;
            cin >> horse;
            auto it = lower_bound(cow.begin(), cow.end(), horse);
            auto lit = it - 1;
            if (it == cow.begin()) {
                lit = cow.begin();
            }
            if (it == cow.end()) {
                it--;
            }

            int current = abs(*it - horse);

            if (ans > current) {
                ans_cnt = 1;
                ans = current;
            } else if (ans == current) {
                ans_cnt++;
            }
            if (it == lit) continue;
            current = abs(*lit - horse);
            if (ans > current) {
                ans_cnt = 1;
                ans = current;
            } else if (ans == current) {
                ans_cnt++;
            }
        }
        cout << "#" << t << " ";
        cout << ans + abs(c1 - c2) << " " << ans_cnt << '\n';
    }
}
