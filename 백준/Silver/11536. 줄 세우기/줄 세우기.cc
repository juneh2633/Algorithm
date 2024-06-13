#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;

    cin >> n;
    vector<string> s(n);
    vector<string> save(n);
    for (auto &i : s) {
        cin >> i;
    }
    save = s;

    sort(s.begin(), s.end());
    bool inc = 1;
    bool dec = 1;
    for (int i = 0; i < n; i++) {
        if (inc) {
            if (save[i] != s[i]) {
                inc = 0;
            }
        }
        if (dec) {
            if (save[i] != s[n - i - 1]) {
                dec = 0;
            }
        }
        if (!inc && !dec) {
            cout << "NEITHER";
            return 0;
        }
    }

    if (inc) {
        cout << "INCREASING";
    } else {
        cout << "DECREASING";
    }
}