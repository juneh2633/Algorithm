#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int ans = 0;
        cin >> n;
        cout << "#" << t;
        priority_queue<int> pq;
        while (n--) {
            int cmd;
            cin >> cmd;
            if (cmd == 1) {
                int x;
                cin >> x;
                pq.push(x);
            } else {
                int ans = -1;
                if (!pq.empty()) {
                    ans = pq.top();
                    pq.pop();
                }
                cout << " " << ans;
            }
        }

        cout << '\n';
    }
    return 0;
}