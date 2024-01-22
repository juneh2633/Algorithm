#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD = 20171109;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T;
    cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll n;
        ll ans;
        ll sum = 0;
        cin >> n >> ans;
        priority_queue<ll> pq;
        priority_queue<ll, vector<ll>, greater<ll> > pqg;
        while (n--) {
            ll a, b;
            cin >> b >> a;
            if (a < b) swap(a, b);
            if (a > ans && ans > b) {
                pq.push(b);
                pqg.push(a);

            } else if (ans > a && a > b) {
                pq.push(a);
                pq.push(b);
                pqg.push(ans);
                ans = pq.top();
                pq.pop();
            } else if (a > b && b > ans) {
                pqg.push(a);
                pqg.push(b);
                pq.push(ans);
                ans = pqg.top();
                pqg.pop();
            }

            sum += ans % MOD;
        }
        cout << "#" << t << " " << sum % MOD << '\n';
    }
    return 0;
}
