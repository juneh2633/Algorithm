#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const ll N = 100001;
ll n, m, k;
/*
    1217
    1217
    1217
*/
pll segTree[4 * N];
pll merge(pll a, pll b) {
    if (a.first < b.first) swap(a, b);
    pll res;
    res.first = a.first;
    res.second = max(a.second, b.first);
    return res;  // 1,2번째로 큰 값
}
void update(ll ptr, ll s, ll e, ll i, ll x) {
    if (s > i || e < i) return;  // i가 보고있는 구간에 없으면 리턴

    if (s == e) {
        segTree[ptr] = {x, 0};
        return;
    }

    update(ptr * 2, s, (s + e) / 2, i, x);
    update(ptr * 2 + 1, (s + e) / 2 + 1, e, i, x);

    segTree[ptr] = merge(segTree[ptr * 2], segTree[ptr * 2 + 1]);
    // 구간합이 아닌 구간에서 큰 값 두개를 저장
}

pll getVal(ll ptr, ll s, ll e, ll l, ll r) {
    if (r < s || e < l) return {0, 0};

    if (l <= s && e <= r) {
        return segTree[ptr];
    }
    return merge(getVal(ptr * 2, s, (s + e) / 2, l, r),
                 getVal(ptr * 2 + 1, (s + e) / 2 + 1, e, l, r));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (ll i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        update(1, 1, n, i, x);
    }
    cin >> m;
    for (ll idx = 0; idx < m; idx++) {
        ll q;
        cin >> q;
        if (q == 1) {
            ll i, v = 0;
            cin >> i >> v;
            update(1, 1, n, i, v);
        } else {
            ll l, r;
            cin >> l >> r;
            pll tmp = getVal(1, 1, n, l, r);
            cout << tmp.first + tmp.second << '\n';
        }
    }
    return 0;
}
