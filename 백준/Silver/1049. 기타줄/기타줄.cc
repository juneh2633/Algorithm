#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int lineSet = 111110;
    int line = 111110;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        lineSet = min(a, lineSet);
        line = min(b, line);
    }
    if (lineSet < line * 6) {
        int ans = n / 6 * lineSet;
        int mod = n % 6;
        cout << ans + min(lineSet, mod * line);

    } else {
        cout << line * n;
    }
}
