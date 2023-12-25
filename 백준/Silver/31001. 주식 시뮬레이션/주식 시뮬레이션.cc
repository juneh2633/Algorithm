#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, q;
    cin >> n >> m >> q;
    unordered_map<ll, vector<string>> mp;
    unordered_map<string, ll> cost;
    unordered_map<string, ll> wallet;
    for (ll i = 0; i < n; i++)
    {
        ll g, p;
        string h;
        cin >> g >> h >> p;
        mp[g].push_back(h);
        cost[h] = p;
        wallet[h] = 0;
    }

    for (ll i = 0; i < q; i++)
    {
        ll x, y, d;
        string a;
        cin >> x;
        if (x == 1)
        {
            cin >> a >> y;

            if (cost[a] * y > m)
            {
                continue;
            }
            wallet[a] += y;
            m = m - cost[a] * y;
        }
        else if (x == 2)
        {
            cin >> a >> y;
            if (wallet[a] == 0)
            {
                continue;
            }
            ll sell = 0;
            if (wallet[a] <= y)
            {
                sell = wallet[a];
                wallet[a] = 0;
            }
            else
            {
                sell = y;
                wallet[a] = wallet[a] - y;
            }
            m = m + cost[a] * sell;
        }
        else if (x == 3)
        {
            cin >> a >> y;
            cost[a] = cost[a] + y;
        }
        else if (x == 4)
        {
            cin >> d >> y;

            for (string st : mp[d])
            {
                cost[st] = cost[st] + y;
            }
        }
        else if (x == 5)
        {
            cin >> d >> y;

            for (string st : mp[d])
            {
                cost[st] = cost[st] * (y + 100) / 100;
                if (cost[st] % 10 != 0)
                {
                    cost[st] = cost[st] - cost[st] % 10;
                }
            }
        }
        else if (x == 6)
        {
            cout << m << '\n';
        }
        else
        {
            ll totalM = m;
            for (auto w : wallet)
            {
                totalM = totalM + cost[w.first] * w.second;
            }
            cout << totalM << '\n';
        }
    }

    return 0;
}