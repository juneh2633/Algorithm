#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int n, m;
int ij[55][55];
int save[55][55];
bool vst[55][55];
int di[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dj[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool in_range(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) {
        return false;
    }
    if (vst[i][j] == 1) {
        return false;
    }
    return true;
}
int bfs(int si, int sj) {
    memset(vst, 0, sizeof(vst));
    queue<tuple<int, int, int>> q;
    vst[si][sj] = 1;
    q.push({si, sj, 0});
    while (!q.empty()) {
        int ci, cj, cw;
        tie(ci, cj, cw) = q.front();
        q.pop();
        for (int d = 0; d < 8; d++) {
            int ii = ci + di[d];
            int jj = cj + dj[d];
            if (!in_range(ii, jj)) {
                continue;
            }
            if (ij[ii][jj] == 1) {
                return cw + 1;
            }
            q.push({ii, jj, cw + 1});
            vst[ii][jj] = 1;
        }
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ij[i][j];
        }
    }
    memset(save, 55555, sizeof(save));

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ij[i][j] == 0) {
                ans = max(ans, bfs(i, j));
            }
        }
    }
    cout << ans;
}