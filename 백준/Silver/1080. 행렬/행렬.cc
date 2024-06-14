#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int n, m;
vector<string> a;
vector<string> b;

bool inRange(int i, int j) {
    if (i < 0 || i >= n) {
        return false;
    }
    if (j < 0 || j >= m) {
        return false;
    }

    return true;
}
void change(int si, int sj) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i + si][j + sj] == '0') {
                a[i + si][j + sj] = '1';
            } else {
                a[i + si][j + sj] = '0';
            }
        }
    }
}
void debug() {
    cout << '\n';
    for (int i = 0; i < n; i++) {
        cout << a[i] << '\n';
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
        cout << b[i] << '\n';
    }
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a.push_back(s);
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        b.push_back(s);
    }
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!inRange(i + 2, j + 2)) {
                continue;
            }

            if (a[i][j] == b[i][j]) {
                continue;
            }
            ans++;
            change(i, j);
        }
    }
    // debug();
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            cout << "-1";
            return 0;
        }
    }
    cout << ans;
}