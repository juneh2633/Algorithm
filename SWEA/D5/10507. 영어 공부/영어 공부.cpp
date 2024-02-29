#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T;

    cin >> T;
    for (ll t = 1; t <= T; t++) {
        int n, p;
        cin >> n >> p;
        vector<int> v(n);
        for (auto &i : v) {
            cin >> i;
        }
        vector<int> empty_days;
        int tmp = 0;
        empty_days.push_back(tmp);

        for (int i = 1; i < n; i++) {
            tmp += v[i] - v[i - 1] - 1;

            empty_days.push_back(tmp);
        }
        int maxAns = 0;
        for (int i = 0; i < n; i++) {
            int l = i;
            int r = n - 1;
            int ans = 0;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                int d = empty_days[mid] - empty_days[i];
                if (d > p) {
                    r = mid - 1;
                } else {
                    ans = v[mid] - v[i] + 1;
                    if(p>d){
                    	ans+=p-d;
                    }
                          l = mid + 1;
                }
            }
            maxAns = max(maxAns, ans);
        }
        cout << "#" << t << " " << maxAns << '\n';
    }
}
