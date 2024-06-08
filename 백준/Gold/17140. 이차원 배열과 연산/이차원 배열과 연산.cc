#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int ij[2222][2222];
int r, c, k;
int curTurn;
int mp[1112];
pii moduleR(pii t) {
    int n, m;
    tie(n, m) = t;
    int nextN = 0;
    int nextM = 0;
    vector<vector<pii>> newIJ(n + 1, vector<pii>(0));
    for (int i = 1; i <= n; i++) {
        memset(mp, 0, sizeof(mp));
        int curSize = 0;
        for (int j = 1; j <= m; j++) {
            mp[ij[i][j]]++;
        }
        if (mp[0] == m) {
            return {0, 0};
        }

        for (int j = 1; j <= 1111; j++) {
            if (mp[j] == 0) {
                continue;
            }
            // j의 갯수, j
            newIJ[i].push_back({mp[j], j});
            curSize += 2;
        }
        sort(newIJ[i].begin(), newIJ[i].end());
        nextM = max(nextM, curSize);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= nextM; j++) {
            int tmp = 1;
            for (auto &cur : newIJ[i]) {
                ij[i][tmp] = cur.second;
                ij[i][tmp + 1] = cur.first;
                tmp += 2;
            }

            while (tmp <= nextM) {
                ij[i][j] = 0;
                tmp++;
            }
        }
    }
    return {n, min(nextM, 100)};
}
pii moduleC(pii t) {
    int n, m;
    tie(n, m) = t;
    int nextN = 0;
    vector<vector<pii>> newIJ(m + 1, vector<pii>(0));
    for (int j = 1; j <= m; j++) {
        memset(mp, 0, sizeof(mp));
        int curSize = 0;
        for (int i = 1; i <= n; i++) {
            mp[ij[i][j]]++;
        }
        if (mp[0] == n) {
            return {0, 0};
        }

        for (int i = 1; i <= 1111; i++) {
            if (mp[i] == 0) {
                continue;
            }

            newIJ[j].push_back({mp[i], i});
            curSize += 2;
        }
        sort(newIJ[j].begin(), newIJ[j].end());
        nextN = max(nextN, curSize);
    }

    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= nextN; i++) {
            int tmp = 1;
            for (auto &cur : newIJ[j]) {
                ij[tmp][j] = cur.second;
                ij[tmp + 1][j] = cur.first;
                tmp += 2;
            }

            while (tmp <= nextN) {
                ij[i][j] = 0;
                tmp++;
            }
        }
    }

    return {min(nextN, 100), m};
}

void print(pii t) {
    int n, m;
    tie(n, m) = t;
    cout << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << ij[i][j];
        }
        cout << '\n';
    }
}

void input() {
    cin >> r >> c >> k;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> ij[i][j];
        }
    }
}

void solution() {
    pii targetSize = {3, 3};
    int time = 0;
    while (ij[r][c] != k) {
        // cout << "time" << time << " n,m " << targetSize.first << " "
        //      << targetSize.second;

        if (targetSize.first >= targetSize.second) {
            // cout << " R";
            targetSize = moduleR(targetSize);
        } else {
            // cout << " C";
            targetSize = moduleC(targetSize);
        }
        // print(targetSize);
        time++;
        if (time > 100) {
            cout << -1;
            return;
        }
    }
    cout << time;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solution();
}
