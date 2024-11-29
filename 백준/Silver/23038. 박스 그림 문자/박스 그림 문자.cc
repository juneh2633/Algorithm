#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
string mp[1111];
int N, M;
int di[4] = {2, 0, -2, 0};
int dj[4] = {0, 2, 0, -2};

bool inRange(int i, int j) {
    if (i < 0 || i >= N * 3) {
        return false;
    }
    if (j < 0 || j >= M * 3) {
        return false;
    }
    return true;
}
void input() {
    cin >> N >> M;
    for (int i = 0; i < 3 * N; i++) {
        cin >> mp[i];
    }
}

void output() {
    for (int i = 0; i < 3 * N; i++) {
        for (int j = 0; j < 3 * M; j++) {
            cout << mp[i][j];
        }
        cout << '\n';
    }
}

void solution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int curI = i * 3 + 1;
            int curJ = j * 3 + 1;
            bool check = 0;
            if (mp[curI][curJ] == '#') {
                continue;
            }
            for (int d = 0; d < 4; d++) {
                int ii = curI + di[d];
                int jj = curJ + dj[d];
                if (!inRange(ii, jj)) {
                    continue;
                }
                if (mp[ii][jj] == '#') {
                    check = 1;
                    mp[curI + di[d] / 2][curJ + dj[d] / 2] = '#';
                }
            }
            if (check) {
                mp[curI][curJ] = '#';
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solution();

    output();
}