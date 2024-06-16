#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int n;
int solution(string &s) {
    int b = 0;
    int r = 0;
    int curBlue = 0;
    int curRed = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            r++;
            if (!curRed) {
                curBlue = 0;
            }

            curRed++;

        } else {
            b++;
            if (!curBlue) {
                curRed = 0;
            }
            curBlue++;
        }
    }
    int ans = 0;
    if (curRed) {
        ans = min(r - curRed, b);
    } else {
        ans = min(b - curBlue, r);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    string s;
    cin >> s;
    int ans = 0;
    ans = solution(s);
    reverse(s.begin(), s.end());
    cout << min(ans, solution(s));
    // cout << "curRed " << curRed << '\n';
    // cout << "curBlue " << curBlue << '\n';
    // cout << "r " << r << '\n';
    // cout << "b " << b << '\n';
}