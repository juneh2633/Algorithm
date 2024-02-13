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
    ll n;
    cin >> n;
    vector<pll> v;
    for (int i = 0; i < n; i++) {
        ll l, r;
        cin >> l >> r;

        v.push_back({l, 1});
        v.push_back({r, -1});
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    ll startP = -1111111111;

    ll current_weight = 0;
    for (auto &i : v) {
        current_weight += i.second;
        if (current_weight == 0) {
            ans += i.first - startP;
            startP = -1111111111;
        }
        if (current_weight == 1 && startP == -1111111111) {
            startP = i.first;
        }
    }
    cout << ans;
}
