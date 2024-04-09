#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
int n, m;
int ij[555][555];
int vst[555][555];
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};

bool in_range(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) {
        return false;
    }
    if (!ij[i][j] || vst[i][j]) {
        return false;
    }
    return true;
}

int bfs(int si, int sj) {
    queue<pii> q;
    vst[si][sj] = 1;
    q.push({si, sj});
    int area = 1;
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int ii = di[d] + cur.first;
            int jj = dj[d] + cur.second;
            if (!in_range(ii, jj)) {
                continue;
            }
            vst[ii][jj] = 1;
            area++;
            q.push({ii, jj});
        }
    }
    return area;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ij[i][j];
        }
    }
    memset(vst, 0, sizeof(vst));
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ij[i][j] == 1 && !vst[i][j]) {
                ans = max(ans, bfs(i, j));
                cnt++;
            }
        }
    }
    cout << cnt << '\n' << ans;
}
