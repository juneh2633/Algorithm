#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<ll> pq;
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++) {
        ll a;
        cin >> a;
        if (a == 0) {
            if (pq.empty()) {
                cout << "0\n";
                continue;
            }
            cout << pq.top() << '\n';
            pq.pop();
            continue;
        }
        pq.push(a);
    }
}
