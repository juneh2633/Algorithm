#include <bits/stdc++.h>
using namespace std;
const int INF = 1e5;
const int N = 111;
int n, m;
int dist[N][N];
int ij[N][N];
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};

bool in_range(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) {
        return false;
    }
    return true;
}
struct wij {
    int w;
    int i;
    int j;
};
struct compare {
    bool operator()(const wij &a, const wij &b) {
        if (a.w != b.w) {
            return a.w < b.w;
        }
        if (a.i != b.i) {
            return a.i < b.i;
        }
        return a.j < b.j;
    }
};

void solution() {
    priority_queue<wij, vector<wij>, compare> pq;
    pq.push({-0, 0, 0});
    dist[0][0] = 0;

    while (!pq.empty()) {
        wij tmp = pq.top();
        pq.pop();

        tmp.w = tmp.w * (-1);
        if (dist[tmp.i][tmp.j] != tmp.w) {
            continue;
        }

        for (int d = 0; d < 4; d++) {
            int ii = tmp.i + di[d];
            int jj = tmp.j + dj[d];

            if (!in_range(ii, jj)) {
                continue;
            }
            if (dist[ii][jj] > dist[tmp.i][tmp.j] + ij[ii][jj]) {
                dist[ii][jj] = dist[tmp.i][tmp.j] + ij[ii][jj];
                pq.push({-dist[ii][jj], ii, jj});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;
    memset(dist, INF, sizeof(dist));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = INF;
        }
    }
    memset(ij, 0, sizeof(ij));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            ij[i][j] = s[j] - '0';
        }
    }
    solution();
    cout << dist[n - 1][m - 1];
}