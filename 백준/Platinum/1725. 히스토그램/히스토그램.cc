#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const ll N = 1e5 + 1;
const ll MAX = 1e9;
ll segTree[262145];
ll arr[N];
ll ans = 0;
ll n;
ll merge(ll x, ll y) {
    if (arr[x] == arr[y]) {
        return min(x, y);
    }
    return arr[x] < arr[y] ? x : y;
}

ll init(ll node, ll s, ll e) {
    if (s == e) {
        return segTree[node] = s;
    }
    ll mid = (s + e) / 2;
    ll l = init(node * 2, s, mid);
    ll r = init(node * 2 + 1, mid + 1, e);

    return segTree[node] = merge(l, r);
}

ll getVal(ll node, ll s, ll e, ll targetS, ll targetE) {
    if (s > targetE || e < targetS) {
        return -1;
    }
    if (targetS <= s && e <= targetE) {
        return segTree[node];
    }

    ll mid = (s + e) / 2;
    ll a = getVal(node * 2, s, mid, targetS, targetE);
    ll b = getVal(node * 2 + 1, mid + 1, e, targetS, targetE);

    if (a == -1) {
        return b;
    } else if (b == -1) {
        return a;
    }

    return merge(a, b);
}

ll getArea(ll l, ll r) {
    ll idx = getVal(1, 1, n, l, r);
    ll area = (ll)(r - l + 1) * arr[idx];
    if (idx - 1 >= l) {
        area = max(area, getArea(l, idx - 1));
    }
    if (idx + 1 <= r) {
        area = max(area, getArea(idx + 1, r));
    }
    return area;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    init(1, 1, n);
    // while (1) {
    //     ll a, b;

    //     cin >> a >> b;
    //     if (a == 0) {
    //         for (ll i = 1; i < 4 * n; i++) {
    //             cout << segTree[i] << " ";
    //         }
    //         cout << '\n';
    //         continue;
    //     }
    //     cout << getVal(1, 1, n, a, b);
    //     cout << '\n';
    // }

    cout << getArea(1, n);
}