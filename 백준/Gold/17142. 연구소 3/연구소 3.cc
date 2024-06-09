#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};
int n, m;
int virusCnt;
int ij[66][66];
int visited[66][66][11];

struct wij {
    int w, i, j;
};
vector<pii> virus;

bool inRange(int i, int j, int mm) {
    if (i < 0 || i >= n) {
        return false;
    }
    if (j < 0 || j >= n) {
        return false;
    }

    if (visited[i][j][mm] || ij[i][j] == 1) {
        return false;
    }
    return true;
}
int selectedVirus[11];
int ans = 99999999;

void debugMap() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ij[i][j] >= 1) {
                cout << '-';
                continue;
            }
            int minTime = 99999999;
            bool check = 0;
            for (int v = 0; v < m; v++) {
                int vv = selectedVirus[v];
                int cur = visited[i][j][vv];
                if (cur) {
                    check = 1;
                }
                minTime = min(minTime, cur);
            }

            if (check == 0) {
                return;
            }
            cout << minTime;
        }
        cout << '\n';
    }
    cout << '\n';
}

void backTracking(int target, int curVirus) {
    if (target == m) {
        int totalTime = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (ij[i][j] >= 1) {
                    continue;
                }
                int minTime = 99999999;
                bool check = 0;
                for (int v = 0; v < m; v++) {
                    int vv = selectedVirus[v];
                    int cur = visited[i][j][vv];
                    if (cur) {
                        check = 1;
                    } else {
                        continue;
                    }
                    minTime = min(minTime, cur);
                }

                if (check == 0) {
                    return;
                }
                totalTime = max(totalTime, minTime);
            }
        }
        ans = min(ans, totalTime);
        // debugMap();
        return;
    }

    for (int t = curVirus + 1; t < virusCnt; t++) {
        selectedVirus[target] = t;
        backTracking(target + 1, t);
    }
}

void bfs(int mm) {
    queue<wij> q;
    q.push({0, virus[mm].first, virus[mm].second});
    visited[virus[mm].first][virus[mm].second][mm] = -1;
    while (!q.empty()) {
        wij cur = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int ii = cur.i + di[d];
            int jj = cur.j + dj[d];
            if (!inRange(ii, jj, mm)) {
                continue;
            }
            visited[ii][jj][mm] = cur.w + 1;
            q.push({cur.w + 1, ii, jj});
        }
    }
}

void solution() {
    memset(visited, 0, sizeof(visited));
    for (int v = 0; v < virusCnt; v++) {
        bfs(v);
    }
    backTracking(0, -1);
    if (ans == 99999999) {
        cout << "-1";
    } else {
        cout << ans;
    }
}
void input() {
    virusCnt = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ij[i][j];
            if (ij[i][j] == 2) {
                virus.push_back({i, j});
                virusCnt++;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solution();
}