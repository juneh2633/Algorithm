#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int n, m, t;
int di[4] = {0, -1, 0, 1};
int dj[4] = {1, 0, -1, 0};
int ij[55][55];
pii upSide;
pii downSide;
bool inRange(int i, int j) {
    if (i < 0 || i >= n) {
        return false;
    }
    if (j < 0 || j >= m) {
        return false;
    }
    if (ij[i][j] == -1) {
        return false;
    }
    return true;
}

void diffusion() {
    int saveIJ[55][55];
    memset(saveIJ, 0, sizeof(saveIJ));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ij[i][j] <= 0) {
                continue;
            }
            int cnt = 0;
            for (int d = 0; d < 4; d++) {
                int ii = i + di[d];
                int jj = j + dj[d];
                if (!inRange(ii, jj)) {
                    continue;
                }
                saveIJ[ii][jj] += ij[i][j] / 5;
                cnt++;
            }
            saveIJ[i][j] += ij[i][j] - (ij[i][j] / 5) * cnt;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ij[i][j] = saveIJ[i][j];
        }
    }
    ij[upSide.first][upSide.second] = -1;
    ij[upSide.first + 1][upSide.second] = -1;
}
void purifierUp() {
    int d = 0;
    int curI = upSide.first;
    int curJ = upSide.second + 1;
    int tmp = 0;
    while (d < 4) {
        int save = ij[curI][curJ];
        int ii = curI + di[d];
        int jj = curJ + dj[d];
        if (!inRange(ii, jj)) {
            d++;
            continue;
        }
        ij[curI][curJ] = tmp;
        tmp = save;
        curI = ii;
        curJ = jj;
    }
    ij[upSide.first - 1][upSide.second] = tmp;
}
void purifierDown() {
    int d = 0;
    int curI = downSide.first;
    int curJ = downSide.second + 1;
    int tmp = 0;
    while (d < 4) {
        int save = ij[curI][curJ];
        int ii = curI + di[d] * (-1);
        int jj = curJ + dj[d];
        if (!inRange(ii, jj)) {
            d++;
            continue;
        }
        ij[curI][curJ] = tmp;
        tmp = save;
        curI = ii;
        curJ = jj;
    }
    ij[downSide.first + 1][downSide.second] = tmp;
}
void debug() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ij[i][j] << "    ";
        }
        cout << '\n';
    }
}

void solution() {
    while (t--) {
        diffusion();
        purifierUp();
        purifierDown();
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += ij[i][j];
        }
    }
    cout << ans + 2;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> t;
    bool flag = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ij[i][j];
            if (ij[i][j] == -1 && flag == 0) {
                upSide = {i, j};
                downSide = {i + 1, j};
                flag = 1;
            }
        }
    }
    solution();
}