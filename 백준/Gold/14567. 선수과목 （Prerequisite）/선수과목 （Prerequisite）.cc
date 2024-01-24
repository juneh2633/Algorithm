#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int rank[1001] = {
        1,
    };
    vector<pii> v;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        v.push_back({b, a});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i <= n; i++) rank[i] = 1;
    for (auto &i : v) {
        int b = i.first;
        int a = i.second;

        rank[b] = max(rank[b], rank[a] + 1);
    }

    for (int i = 1; i <= n; i++) {
        cout << rank[i] << ' ';
    }
}
