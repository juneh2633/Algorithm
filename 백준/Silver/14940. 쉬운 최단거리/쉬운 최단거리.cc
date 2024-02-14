#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
int n, m;
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};
int ij[1111][1111];
int vst[1111][1111];
int ans[1111][1111];
bool in_range(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) {
        return false;
    }

    if (vst[i][j] == true || ij[i][j] == 0) {
        return false;
    }
    return true;
}
struct ijw {
    int i, j, w;
};
void solution(int si, int sj) {
    queue<ijw> q;
    q.push({si, sj, 0});

    while (!q.empty()) {
        ijw tmp = q.front();
        int weight = tmp.w + 1;
        q.pop();
        for (int d = 0; d < 4; d++) {
            int ii = tmp.i + di[d];
            int jj = tmp.j + dj[d];
            if (!in_range(ii, jj)) {
                continue;
            }
            vst[ii][jj] = true;
            ans[ii][jj] = weight;
            q.push({ii, jj, weight});
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int start_i, start_j;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ij[i][j];
            if (ij[i][j] == 2) {
                start_i = i;
                start_j = j;
            }
        }
    }

    solution(start_i, start_j);
    ans[start_i][start_j] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ij[i][j] == 1 && vst[i][j] == 0) {
                cout << "-1 ";
                continue;
            }
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}