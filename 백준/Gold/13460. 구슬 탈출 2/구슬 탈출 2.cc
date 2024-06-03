#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;

int n, m;
struct rb {
    int ri, rj, bi, bj, w;
};

int ddr, ddb;
string ij[11];
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};

pii query(int i, int j, int di, int dj, int rgb) {
    int ii = i + di, jj = j + dj;
    int tmp = 0;
    while (ij[ii][jj] != '#' && ij[ii][jj] != 'O') {
        ii += di;
        jj += dj;
        tmp++;
    }
    if (rgb == 0) {
        ddr = tmp;
    } else {
        ddb = tmp;
    }
    return {ii - di, jj - dj};
}
int test[11];

void bfs(pii sr, pii sb) {
    queue<rb> q;
    q.push({sr.first, sr.second, sb.first, sb.second, 0});

    while (!q.empty()) {
        int ri, rj, bi, bj;
        int w;
        rb tmp = q.front();
        q.pop();
        ri = tmp.ri;
        rj = tmp.rj;
        bi = tmp.bi;
        bj = tmp.bj;
        w = tmp.w;
        if (w >= 10) {
            continue;
        }

        for (int d = 0; d < 4; d++) {
            int rii = ri;
            int rjj = rj;
            int bii = bi;
            int bjj = bj;
            tie(rii, rjj) = query(rii, rjj, di[d], dj[d], 0);
            tie(bii, bjj) = query(bii, bjj, di[d], dj[d], 1);

            if (ij[bii + di[d]][bjj + dj[d]] == 'O') {
                continue;
            }

            if (ij[rii + di[d]][rjj + dj[d]] == 'O') {
                cout << w + 1;
                return;
            }
            if (bii == rii && bjj == rjj) {
                if (ddr > ddb) {
                    rii -= di[d];
                    rjj -= dj[d];
                } else {
                    bii -= di[d];
                    bjj -= dj[d];
                }
            }

            q.push({rii, rjj, bii, bjj, w + 1});
        }
    }

    cout << "-1";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    pii r, b, o;
    for (int i = 0; i < n; i++) {
        cin >> ij[i];
        for (int j = 0; j < m; j++) {
            if (ij[i][j] == 'R') {
                r = {i, j};
            }
            if (ij[i][j] == 'B') {
                b = {i, j};
            }
            if (ij[i][j] == 'O') {
                o = {i, j};
            }
        }
    }
    bfs(r, b);
}