#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int di[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dj[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int ci[4] = {1, 1, -1, -1};
int cj[4] = {1, -1, 1, -1};

int ij[66][66];
vector<pii> cloud;
map<pii, bool> ban;
int n, m;

bool inRange(int i, int j) {
    if (i < 0 || i >= n) {
        return false;
    }
    if (j < 0 || j >= n) {
        return false;
    }

    return true;
}

pii rangeChange(int i, int j) {
    int ii = (i + n * 51) % n;
    int jj = (j + n * 51) % n;
    return {ii, jj};
}
void unlockBanAll() { ban.clear(); }
void pushCloud() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ij[i][j] < 2 || ban[{i, j}]) {
                continue;
            }
            ij[i][j] = ij[i][j] - 2;
            cloud.push_back({i, j});
        }
    }
}
void popAllCloud() {
    while (!cloud.empty()) {
        pii cur = cloud.back();
        ban[cur] = true;
        cloud.pop_back();
    }
}

void moveAllCloud(int d, int s) {
    for (auto &cur : cloud) {
        int ii = cur.first + di[d] * s;
        int jj = cur.second + dj[d] * s;
        pii newCur = rangeChange(ii, jj);
        cur = newCur;
        ij[newCur.first][newCur.second]++;
    }
}
void showMeTheWater() {
    for (auto &cur : cloud) {
        int i = cur.first;
        int j = cur.second;

        for (int d = 0; d < 4; d++) {
            int ii = i + ci[d];
            int jj = j + cj[d];

            if (!inRange(ii, jj)) {
                continue;
            }

            if (ij[ii][jj] > 0) {
                ij[i][j]++;
            }
        }
    }
}

void calculateWater() {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += ij[i][j];
        }
    }
    cout << sum;
}
void query(int d, int s) {
    moveAllCloud(d - 1, s);

    showMeTheWater();
    popAllCloud();
    pushCloud();
    unlockBanAll();
}
void solution() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ij[i][j];
        }
    }
    cloud.push_back({n - 1, 0});
    cloud.push_back({n - 1, 1});
    cloud.push_back({n - 2, 0});
    cloud.push_back({n - 2, 1});
    for (int i = 0; i < m; i++) {
        int d, s;
        cin >> d >> s;

        query(d, s);
    }
}
void Print() {
    cout << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ij[i][j] << " ";
        }
        cout << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();
    calculateWater();
}