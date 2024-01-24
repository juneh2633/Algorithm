#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T;
    ll n;
    ll ans = -1;
    ll sq;
    cin >> T;
    for (ll t = 1; t <= T; t++) {
        cin >> n;
        ans = -1;
        n *= 2;
        sq = sqrt(n);
        if (sq * (sq + 1) == n) ans = sq;
        cout << "#" << t << " " << ans << '\n';
    }
    return 0;
}
