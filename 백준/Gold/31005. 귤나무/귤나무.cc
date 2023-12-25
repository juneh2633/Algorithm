#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll m, n;
    ll sum = 0;
    cin >> n >> m;
    vector<ll> a(n);
    vector<bool> check(n);

    for (ll i = 0; i < n; i++) cin >> a[i];

    for (auto &i : a) sum += i;

    while (1) {
        ll tmp = m;
        m %= sum;

        for (int i = 0; i < n; i++) {
            if (check[i]) continue;

            if (m < a[i]) {
                check[i] = 1;
                sum -= a[i];
            } else
                m -= a[i];
        }

        if (tmp == m || sum == 0) break;
    }

    cout << m;

    return 0;
}