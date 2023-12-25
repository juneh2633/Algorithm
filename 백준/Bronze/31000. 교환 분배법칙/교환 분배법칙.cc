#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int ans = 0;
    cin >> n;
    ans += (2 * n + 1) * (2 * n + 1);
    for (int i = n * (-1); i <= n; i++)
    {
        for (int j = n * (-1); j <= n; j++)
        {
            if (i == 0)
            {
                continue;
            }
            int k = 1 - i - j;
            if (k > n || k < n * (-1))
                continue;
            ans++;
        }
    }
    cout << ans;
    return 0;
}