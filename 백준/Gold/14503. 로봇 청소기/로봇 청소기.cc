#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int n, m;
int r, c, curD;

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};
int ij[55][55];
int cnt;

bool inRange(int i, int j) {
    if (i < 0 || i >= n) {
        return false;
    }
    if (j < 0 || j >= m) {
        return false;
    }
    if (ij[i][j] == 1) {
        return false;
    }
    return true;
}

bool goBack(int d) {
    int dd = (d + 2) % 4;
    if (!inRange(r + di[dd], c + dj[dd])) {
        return false;
    }

    r += di[dd];
    c += dj[dd];
    return true;
}

bool goFront(int d) {
    if (!inRange(r + di[d], c + dj[d])) {
        return false;
    }
    if (ij[r + di[d]][c + dj[d]]) {
        return false;
    }
    r += di[d];
    c += dj[d];
    return true;
}

void CleanQuery() {
    if (ij[r][c] == 0) {
        ij[r][c] = 2;
        cnt++;
    }

    for (int q = 0; q < 4; q++) {
        curD = (curD + 3) % 4;
        if (goFront(curD)) {
            CleanQuery();
            return;
        }
    }
    if (!goBack(curD)) {
        return;
    }

    CleanQuery();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    cin >> r >> c >> curD;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ij[i][j];
        }
    }
    cnt = 0;
    CleanQuery();
    cout << cnt;
}