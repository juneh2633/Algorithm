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
    int cntOdd = 0;
    int alreadyInOdd = 0;
    int cntEven = 0;
    int alreadyInEven = 0;
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