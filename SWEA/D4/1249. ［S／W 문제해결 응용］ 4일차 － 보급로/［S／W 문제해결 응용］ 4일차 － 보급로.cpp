#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
const int INF = 1e4;

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
int ij[111][111];
bool vst[111][111];
int dist[111][111];
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};
int n;

bool in_range(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= n) {
        return false;
    }
    if (vst[i][j] == true) {
        return false;
    }
    return true;
}

void input() {
    memset(vst, 0, sizeof(vst));
    memset(ij, 0, sizeof(ij));
    memset(dist, INF, sizeof(dist));
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            ij[i][j] = s[j] - '0';
        }
    }
}

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
                vst[ii][jj] = true;

                pq.push({-dist[ii][jj], ii, jj});
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T;

    cin >> T;
    for (ll t = 1; t <= T; t++) {
        input();
        solution();
        cout << "#" << t << " " << dist[n - 1][n - 1] << '\n';
    }
}
