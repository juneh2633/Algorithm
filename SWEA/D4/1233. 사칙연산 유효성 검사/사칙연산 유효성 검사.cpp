#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 10;
    for (int t = 1; t <= T; t++) {
        int n;

        int ans = 1;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            char ch;

            cin >> i >> ch;

            if (i <= n / 2) {
                int left, right;

                if (i == n / 2 && n % 2 == 0)
                    cin >> left;

                else
                    cin >> left >> right;

                if (ch >= '0' && ch <= '9') ans = 0;

            }

            else {
                if (!(ch >= '0' && ch <= '9')) ans = 0;
            }
        }
        cout << "#" << t << " ";
        cout << ans;
        cout << '\n';
    }
}
