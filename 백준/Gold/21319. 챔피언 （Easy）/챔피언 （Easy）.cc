#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const ll N = 1e5 + 1;
const ll MAX = 1e9;
ll n;
bool check(vector<pll>& v, int idx) {
    ll power = v[idx].first + v[idx].second - 1;
    // cout << "mid: " << idx << ". ";
    // cout << "start power: " << power << " ";
    for (int i = idx + 1; i < v.size(); i++) {
        // cout << "@@@@" << power + v[i].second - v[idx].second - 1 << '\n';
        if (power + v[i].second - v[idx].second - 1 > v[i].first) {
        } else {
            return false;
        }
    }

    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<pll> v;
    map<ll, ll> mp;
    if (n == 1) {
        cin >> n;
        cout << "1";
        return 0;
    }
    for (ll i = 1; i <= n; i++) {
        ll a;
        cin >> a;
        if (mp[a] != 0) {
            continue;
        }
        mp[a]++;
        v.push_back({a, i});
    }

    ll l = 1;
    ll r = v.size() - 1;
    ll s = n + 2;

    while (l <= r) {
        ll mid = r - (r - l) / 2;

        if (check(v, mid)) {
            s = min(s, mid);

            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    ll cnt = 0;

    for (ll i = s; i < v.size(); i++) {
        cout << v[i].second << " ";
        cnt++;
    }
    if (cnt == 0) {
        cout << "-1";
    }
}
