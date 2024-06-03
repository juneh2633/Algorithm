#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int n, m;
int ans;
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};
int ij[11][11];
int zeroIJ[11][11];
int wallCount = 0;
struct cctv {
    int i, j;
    int type;
};
vector<cctv> cctv;
int cctvDirect[8];

void debugMap() {
    cout << "@@@@@@\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << zeroIJ[i][j] << " ";
        }
        cout << '\n';
    }
    cout << "@@@@@'\n";
}

bool inRange(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) {
        return false;
    }
    if (ij[i][j] == 6) {
        return false;
    }
    return true;
}

void paintMap(int i, int j, int type, int direct) {
    int curI = i;
    int curJ = j;
    if (type == 1) {
        while (inRange(curI, curJ)) {
            zeroIJ[curI][curJ] = -1;
            curI += di[direct];
            curJ += dj[direct];
        }
    }
    if (type == 2) {
        while (inRange(curI, curJ)) {
            zeroIJ[curI][curJ] = -1;
            curI += di[direct];
            curJ += dj[direct];
        }
        curI = i;
        curJ = j;
        while (inRange(curI, curJ)) {
            zeroIJ[curI][curJ] = -1;
            curI += di[direct + 2];
            curJ += dj[direct + 2];
        }
    }
    if (type == 3) {
        while (inRange(curI, curJ)) {
            zeroIJ[curI][curJ] = -1;
            curI += di[direct];
            curJ += dj[direct];
        }
        curI = i;
        curJ = j;
        while (inRange(curI, curJ)) {
            zeroIJ[curI][curJ] = -1;
            curI += di[(direct + 1) % 4];
            curJ += dj[(direct + 1) % 4];
        }
    }
    if (type == 4) {
        for (int d = 0; d < 3; d++) {
            curI = i;
            curJ = j;
            while (inRange(curI, curJ)) {
                zeroIJ[curI][curJ] = -1;
                curI += di[(direct + d) % 4];
                curJ += dj[(direct + d) % 4];
            }
        }
    }
    if (type == 5) {
        for (int d = 0; d < 4; d++) {
            curI = i;
            curJ = j;
            while (inRange(curI, curJ)) {
                zeroIJ[curI][curJ] = -1;
                curI += di[(direct + d) % 4];
                curJ += dj[(direct + d) % 4];
            }
        }
    }
}

int countMap() {
    int result = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (zeroIJ[i][j] == 0) {
                result++;
            }
        }
    }
    return result;
}

void solution(int target) {
    if (target == cctv.size()) {
        memset(zeroIJ, 0, sizeof(zeroIJ));
        for (int t = 0; t < cctv.size(); t++) {
            paintMap(cctv[t].i, cctv[t].j, cctv[t].type, cctvDirect[t]);
        }

        ans = min(ans, countMap());
        // debugMap();
        return;
    }

    int type = cctv[target].type;

    if (type == 1 || type == 3 || type == 4) {
        for (int t = 0; t < 4; t++) {
            cctvDirect[target] = t;
            solution(target + 1);
        }
    }
    if (type == 2) {
        for (int t = 0; t < 2; t++) {
            cctvDirect[target] = t;
            solution(target + 1);
        }
    }
    if (type == 5) {
        cctvDirect[target] = 0;
        solution(target + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ij[i][j];
            if (ij[i][j] > 0 && ij[i][j] < 6) {
                cctv.push_back({i, j, ij[i][j]});
            }
            if (ij[i][j] == 6) {
                wallCount++;
            }
        }
    }
    ans = n * m;

    solution(0);
    cout << ans - wallCount;
}