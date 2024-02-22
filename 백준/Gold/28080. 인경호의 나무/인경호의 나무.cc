#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
ll MOD = 1e9 + 7;
ll n, m;
ll tree[2222][2];
ll node[2222];
vector<ll> v;
void inOrder(ll target) {
    if (target == -1) {
        return;
    }
    inOrder(tree[target][0]);
    v.push_back(node[target]);
    inOrder(tree[target][1]);
}
ll dp_c[2001][2001];

ll nCr(int n, int r) {
    if (n == r || r == 0)
        return 1;
    else {
        if (dp_c[n][r] != 0) {
            return dp_c[n][r];
        } else
            return dp_c[n][r] = (nCr(n - 1, r - 1) + nCr(n - 1, r)) % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    memset(node, 0, sizeof(node));
    // memset(tree, 0, sizeof(tree));
    for (int i = 1; i <= n; i++) {
        cin >> node[i] >> tree[i][0] >> tree[i][1];
    }
    inOrder(1);
    ll s = 0;
    ll tmpSize = 0;
    ll ans = 1;

    for (ll i = 0; i < v.size(); i++) {
        if (v[i] == -1) {
            tmpSize++;
            continue;
        }

        if (tmpSize > 0) {
            int d = v[i] - s - 1;
            ans = ans * nCr(d, tmpSize) % MOD;

            tmpSize = 0;
        }
        s = v[i];
    }
    if (tmpSize > 0) {
        int d = m - s;
        ans = ans * nCr(d, tmpSize) % MOD;
    }
    cout << ans % MOD;
}
