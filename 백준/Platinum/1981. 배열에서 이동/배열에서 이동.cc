#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const ll N = 1e5 + 1;
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};
int n;
int ij[111][111];
bool vst[111][111];

bool in_range(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= n || vst[i][j]) {
        return false;
    }
    return true;
}

bool bfs(int min_num, int max_num) {
    memset(vst, 0, sizeof(vst));
    queue<pii> q;
    vst[0][0] = 1;
    q.push({0, 0});
    int f_min = 201;
    int f_max = -1;
    bool finish = 0;
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        if (cur.first == n - 1 && cur.second == n - 1) {
            return true;
        }
        for (int d = 0; d < 4; d++) {
            int ii = cur.first + di[d];
            int jj = cur.second + dj[d];
            if (!in_range(ii, jj)) {
                continue;
            }
            if (ij[ii][jj] < min_num || ij[ii][jj] > max_num) {
                continue;
            }

            vst[ii][jj] = 1;
            q.push({ii, jj});
        }
    }
    return false;
}
bool check_ans(int min_num, int max_num, int val) {
    for (int i = min_num; i <= max_num; i++) {
        if (ij[0][0] < i || ij[0][0] > i + val) {
            continue;
        }
        if (bfs(i, i + val)) {
            return true;
        }
    }
    return false;
}
int parametric_search(int l, int r) {
    int min_num = l;
    int max_num = r;

    int ans = r - l;
    l = 0;
    r = r - l;

    while (l <= r) {
        int mid = r - (r - l) / 2;
        if (check_ans(min_num, max_num, mid)) {
            ans = min(ans, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int l = 201;
    int r = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ij[i][j];
            l = min(l, ij[i][j]);
            r = max(r, ij[i][j]);
        }
    }
    cout << parametric_search(l, r);
}