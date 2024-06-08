#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int di[5] = {0, -1, 1, 0, 0};
int dj[5] = {0, 0, 0, 1, -1};
struct Shark {
    int r, c, s, d, z;
    int isDead;
    bool operator<(const Shark& other) const {
        if (r == other.r) {
            if (c == other.c) {
                return z > other.z;
            }
            return c < other.c;
        }
        return r < other.r;
    }
};
int n, m;

vector<Shark> shark;
int inRange(int i, int j) {
    if (i <= 0) {
        return 2;
    }
    if (i > n) {
        return 1;
    }
    if (j <= 0) {
        return 3;
    }

    if (j > m) {
        return 4;
    }
    return 0;
}

void fishUpdate() {
    map<pii, int> mp;
    for (auto& cur : shark) {
        if (cur.isDead) {
            continue;
        }

        int leftS = cur.s;
        while (leftS > 0) {
            int moveStep = 0;
            switch (cur.d) {
                case 1:  // Up
                    moveStep = min(leftS, cur.r - 1);
                    cur.r -= moveStep;
                    leftS -= moveStep;
                    if (cur.r == 1) {
                        cur.d = 2;
                    }
                    break;
                case 2:  // Down
                    moveStep = min(leftS, n - cur.r);
                    cur.r += moveStep;
                    leftS -= moveStep;
                    if (cur.r == n) {
                        cur.d = 1;
                    }
                    break;
                case 3:  // Right
                    moveStep = min(leftS, m - cur.c);
                    cur.c += moveStep;
                    leftS -= moveStep;
                    if (cur.c == m) {
                        cur.d = 4;
                    }
                    break;
                case 4:  // Left
                    moveStep = min(leftS, cur.c - 1);
                    cur.c -= moveStep;
                    leftS -= moveStep;
                    if (cur.c == 1) {
                        cur.d = 3;
                    }
                    break;
            }
        }

        mp[{cur.r, cur.c}] = max(mp[{cur.r, cur.c}], cur.z);
    }

    for (auto& cur : shark) {
        if (mp[{cur.r, cur.c}] > cur.z) {
            cur.isDead = 1;
        }
    }
}
void debug() {
    int ij[111][111];
    memset(ij, 0, sizeof(ij));

    for (int cur = 0; cur < shark.size(); cur++) {
        if (shark[cur].isDead) {
            continue;
        }
        ij[shark[cur].r][shark[cur].c] = shark[cur].z;
        cout << shark[cur].z << " r,c== " << shark[cur].r << " " << shark[cur].c
             << "@@\n";
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << ij[i][j];
        }
        cout << '\n';
    }
    cout << "@@@@@@@@@@@@@\n";
}

void solution() {
    int ans = 0;

    int fisherJ = 1;

    while (fisherJ <= m) {
        sort(shark.begin(), shark.end());

        for (auto& cur : shark) {
            if (cur.c == fisherJ && !cur.isDead) {
                ans += cur.z;
                cur.isDead = 1;
                break;
            }
        }
        // debug();
        fishUpdate();
        fisherJ++;
    }
    cout << ans;
}

void input() {
    int q;
    cin >> n >> m >> q;
    while (q--) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        shark.push_back({r, c, s, d, z, 0});
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solution();
}