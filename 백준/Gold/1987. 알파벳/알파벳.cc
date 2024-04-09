#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
int n, m;
string ij[22];
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};
bool vst[22][22];
bool charVst[27] = {
    0,
};
bool in_range(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) {
        return false;
    }
    if (vst[i][j] || charVst[ij[i][j] - 'A']) {
        return false;
    }
    return true;
}
int ans = 1;
void solution(int cnt, int ti, int tj) {
    ans = max(ans, cnt);
    for (int d = 0; d < 4; d++) {
        int ii = ti + di[d];
        int jj = tj + dj[d];
        if (!in_range(ii, jj)) {
            continue;
        }
        vst[ii][jj] = 1;
        charVst[ij[ii][jj] - 'A'] = 1;

        solution(cnt + 1, ii, jj);
        vst[ii][jj] = 0;
        charVst[ij[ii][jj] - 'A'] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> ij[i];
    }
    memset(vst, 0, sizeof(vst));
    memset(charVst, 0, sizeof(charVst));
    charVst[ij[0][0] - 'A'] = 1;
    vst[0][0] = 1;
    solution(1, 0, 0);
    cout << ans;
}