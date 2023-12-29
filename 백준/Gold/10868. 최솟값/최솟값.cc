#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const ll N = 100001;
const ll MAX = 1000000001;
const ll MIN = -1;
ll n, m, k;

pll segTree[4 * N];
pll merge(pll a, pll b) {
    pll res;
    res.first = max(a.first, b.first);
    res.second = min(a.second, b.second);
    return res;
}
void update(ll ptr, ll s, ll e, ll i, ll x) {
    if (s > i || e < i) return;

    if (s == e) {
        pll res;
        if (segTree[ptr].first == 0) {
            res.first = x;
        } else {
            max(x, segTree[ptr].first);
        }
        if (segTree[ptr].second == 0) {
            res.second = x;
        } else {
            min(x, segTree[ptr].second);
        }
        segTree[ptr] = res;
        return;
    }

    update(ptr * 2, s, (s + e) / 2, i, x);
    update(ptr * 2 + 1, (s + e) / 2 + 1, e, i, x);

    segTree[ptr] = merge(segTree[ptr * 2], segTree[ptr * 2 + 1]);
}

pll getVal(ll ptr, ll s, ll e, ll l, ll r) {
    if (r < s || e < l) return {MIN, MAX};

    if (l <= s && e <= r) {
        return segTree[ptr];
    }
    return merge(getVal(ptr * 2, s, (s + e) / 2, l, r),
                 getVal(ptr * 2 + 1, (s + e) / 2 + 1, e, l, r));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        update(1, 1, n, i, x);
    }

    for (ll idx = 0; idx < m; idx++) {
        ll l, r;
        cin >> l >> r;
        pll tmp = getVal(1, 1, n, l, r);
        cout << tmp.second<< '\n';
    }
    return 0;
}
