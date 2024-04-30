#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll cntOdd = 0;
    ll alreadyInOdd = 0;
    ll cntEven = 0;
    ll alreadyInEven = 0;
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] % 2 == 0) {
            cntEven += i - alreadyInEven;
            alreadyInEven++;

        } else {
            cntOdd += i - alreadyInOdd;
            alreadyInOdd++;
        }
    }
    cout << min(cntOdd, cntEven);
}