#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y;
    cin >> x >> y;
    if (x > y) {
        cout << x + y;
        return 0;
    }
    cout << y - x;
}