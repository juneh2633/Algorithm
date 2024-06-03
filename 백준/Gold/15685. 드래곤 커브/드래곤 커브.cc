#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int xy[111][111];

vector<vector<int>> gen(11, vector<int>(0));
bool inRange(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) {
        return false;
    }

    return true;
}

void createGen(int target) {
    if (target == 11) {
        return;
    }
    int finalDirection = 0;
    for (auto &i : gen[target - 1]) {
        gen[target].push_back(i);
        finalDirection = i;
    }
    for (int i = gen[target - 1].size() - 1; i >= 0; i--) {
        gen[target].push_back((gen[target - 1][i] + 1) % 4);
    }
    createGen(target + 1);
}

void createLine(int x, int y, int d, int g) {
    xy[x][y] = 1;
    for (auto &i : gen[g]) {
        x += dx[(d + i) % 4];
        y += dy[(d + i) % 4];
        xy[x][y] = 1;
    }
}

void countSquare() {
    int ans = 0;
    for (int y = 0; y <= 99; y++) {
        for (int x = 0; x <= 99; x++) {
            if (xy[x][y] && xy[x + 1][y] && xy[x][y + 1] && xy[x + 1][y + 1]) {
                ans++;
            }
        }
    }
    cout << ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    gen[0].push_back(0);
    createGen(1);
    memset(xy, 0, sizeof(xy));
    for (int i = 0; i < n; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        createLine(x, y, d, g);
    }

    countSquare();
}
