#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
string s, t;
int len;
int ans = 0;
void input() { cin >> s >> t; }

void back() {
    if (t.length() == len) {
        if (s == t) {
            ans = 1;
        } else {
            ans = 0;
        }
        return;
    }
    if (t[t.length() - 1] == 'A') {
        t.pop_back();
    } else {
        t.pop_back();
        reverse(t.begin(), t.end());
    }
    back();
}

void solution() {
    len = s.length();
    back();
    cout << ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solution();
}
