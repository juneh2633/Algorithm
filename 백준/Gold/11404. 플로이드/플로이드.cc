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
    int tree[111][111] = {
        0,
    };
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            tree[i][j] = 999999999;
            if (i == j) tree[i][j] = 0;
        }
    }
    while (m--) {
        int a, b, w;
        cin >> a >> b >> w;
        tree[a][b] = min(tree[a][b], w);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (tree[i][k] + tree[k][j] < tree[i][j]) {
                    tree[i][j] = tree[i][k] + tree[k][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || tree[i][j] == 999999999) {
                cout << 0 << " ";
                continue;
            }

            cout << tree[i][j] << " ";
        }
        cout << '\n';
    }
}