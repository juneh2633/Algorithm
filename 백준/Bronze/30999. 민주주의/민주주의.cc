#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    m = m / 2;
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        sort(s.begin(), s.end());
        if (s[m] == 'O')
        {
            ans++;
        }
    }
    cout << ans;

    return 0;
}