#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const ll N = 1e5 + 1;
const ll MAX = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll d;
    string s;
    ll x, y;
    cin >> d >> s >> x >> y;
    y = -y;
    ll bit = 1LL << d;
    ll curX = 0;
    ll curY = 0;
    for (ll i = 0; i < d; i++) {
        curX <<= 1;
        curY <<= 1;
        if (s[i] <= '2') s[i] = s[i] == '1' ? '2' : '1';
        if (s[i] - '1' & 1) curX++;
        if (s[i] - '1' & 2) curY++;
    }

    curX += x, curY += y;
    if (!(0 <= curX && curX < bit) || !(0 <= curY && curY < bit)) {
        cout << -1 << '\n';
        return 0;
    }
    for (ll i = d - 1; i >= 0; i--) {
        bool flag1 = curX & (1LL << i);
        bool flag2 = curY & (1LL << i);
        if (flag1 && flag2) {
            cout << 4;
        } else if (flag1) {
            cout << 1;
        } else if (flag2) {
            cout << 3;
        } else {
            cout << 2;
        }
    }
    cout << '\n';
}