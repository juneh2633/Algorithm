#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};
int n, m;

deque<int> ij[66];

bool inRange(int i, int j) {
    if (i < 0 || i >= n) {
        return false;
    }

    return true;
}

pii convertRange(int i, int j) {
    int jj = (j + m) % m;
    return {i, jj};
}

void turnClockWise(int x) {
    int tmp = ij[x].back();

    ij[x].push_front(tmp);
    ij[x].pop_back();
}
void turnUnClockWise(int x) {
    int tmp = ij[x].front();
    ij[x].push_back(tmp);
    ij[x].pop_front();
}

bool bfs(int si, int sj) {
    bool flag = 0;
    bool visited[66][66];
    int pivot = ij[si][sj];

    memset(visited, 0, sizeof(visited));
    queue<pii> q;
    q.push({si, sj});
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int ii = cur.first + di[d];
            int jj = cur.second + dj[d];
            if (!inRange(ii, jj)) {
                continue;
            }
            tie(ii, jj) = convertRange(ii, jj);
            if (visited[ii][jj] || ij[ii][jj] != pivot) {
                continue;
            }
            ij[ii][jj] = -999999;
            visited[ii][jj] = 1;
            q.push({ii, jj});
            flag = 1;
        }
    }

    if (flag) {
        ij[si][sj] = -999999;
        return true;
    }
    return false;
}

void deleteTable() {
    bool flag = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ij[i][j] == -999999) {
                continue;
            }
            bool delCheck = bfs(i, j);
            if (!flag) {
                flag = delCheck;
            }
        }
    }

    if (!flag) {
        int sumAll = 0;
        int cntAll = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ij[i][j] == -999999) {
                    continue;
                }
                sumAll += ij[i][j];
                cntAll++;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ij[i][j] == -999999) {
                    continue;
                }
                if (ij[i][j] * cntAll > sumAll) {
                    ij[i][j]--;
                    continue;
                }
                if (ij[i][j] * cntAll < sumAll) {
                    ij[i][j]++;
                    continue;
                }
            }
        }
    }
}

void input() {
    int t;

    cin >> n >> m >> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int a;
            cin >> a;
            ij[i].push_back(a);
        }
    }

    while (t--) {
        int x, d, k;
        cin >> x >> d >> k;
        for (int i = x; i <= n; i += x) {
            for (int j = 0; j < k; j++) {
                if (d) {
                    turnUnClockWise(i - 1);
                } else {
                    turnClockWise(i - 1);
                }
            }
        }
        deleteTable();
    }
}

void sumAll() {
    int sumAll = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ij[i][j] == -999999) {
                continue;
            }
            sumAll += ij[i][j];
        }
    }
    cout << sumAll;
}

void Print() {
    cout << '\n';

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ij[i][j] << " ";
        }
        cout << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    sumAll();
    // Print();
}