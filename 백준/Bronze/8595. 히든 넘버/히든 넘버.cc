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
    ll ans = 0;
    string cur = "";
    bool start = 0;
    for (ll i = 0; i < n; i++) {
        char a;
        cin >> a;
        if (start == 0 && a == '0') {
            continue;
        }
        if (a - '0' >= 0 && a - '0' <= 9) {
            cur += a;
            start = 1;
        } else {
            if (start) {
                start = 0;
                ans += stoll(cur);
                cur = "";
            }
        }
    }
    if (cur.length() != 0) {
        ans += stoll(cur);
    }
    cout << ans;
}