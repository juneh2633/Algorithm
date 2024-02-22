#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll n, k;
ll ans = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    vector<ll> pSum(n);
    for (ll i = 0; i < n; i++) {
        cin >> pSum[i];
        if (i == 0) {
            continue;
        }
        pSum[i] += pSum[i - 1];
    }

    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {

        ans += mp[pSum[i] - (i + 1) * k]++;
    }
    ans += mp[0];
    cout << ans;
    return 0;
}