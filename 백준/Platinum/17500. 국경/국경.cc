#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const ll N = 1e5 + 1;
const ll MAX = 1e9;
int n;
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};
int bound[15][15] = {
    0,
};
int zone[5][5];
int vst[5][5];
bool visited[5][5];
string animal[4];
// clang-format off
string ij[9] = {
    "+   +   +   +   +",
    "  .   .   .   .  ",
    "+   +   +   +   +",
    "  .   .   .   .  ", 
    "+   +   +   +   +", 
    "  .   .   .   .  ",
    "+   +   +   +   +", 
    "  .   .   .   .  ", 
    "+   +   +   +   +"
    };
/// ...
// clang-format on

//////debug-- call_bound-------/////////
void call_bound() {
    cout << "\nDEBUG@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    for (int i = 0; i < 2 * n + 1; i++) {
        for (int j = 0; j < 2 * n + 1; j++) {
            cout << bound[i][j] << " ";
        }
        cout << '\n';
    }
    cout << "DEBUG@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
}
void call_zone() {
    cout << "\nDEBUG___ZONE____@@@@@@@@@\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << zone[i][j] << " ";
        }
        cout << '\n';
    }
    cout << "DEBUG@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
}

/////makeLine--------------------------------------------------------------------------------///////////

void makeLine() {
    // call_bound();
    // call_zone();
    for (int i = 0; i < n * 2 + 1; i++) {
        for (int j = 0; j < n * 2 + 1; j++) {
            if (bound[i][j] == 1) {
                if (i % 2 == 0) {
                    ij[i][j * 2] = '-';
                    ij[i][j * 2 - 1] = '-';
                    ij[i][j * 2 + 1] = '-';

                } else {
                    ij[i][j * 2] = '|';
                }
            }
        }
    }
}
////////
/// in_range--------------------------------------//////////////////////////////////////////////////////
bool in_range(int i, int j) {
    if (i < 0 || i > n || j < 0 || j > n) {
        return false;
    }
    if (vst[i][j]) {
        return false;
    }
    return true;
}

bool haveAns = 0;

/////////wallCheck---------------------------///////////////////////////////////////////////////////

bool wallCheck(int i, int j, int ii, int jj) {
    if (i != ii) {
        if (bound[i + ii + 1][j * 2 + 1] == 1) {
            return true;
        } else {
            return false;
        }
    }

    if (bound[i * 2 + 1][j + jj + 1] == 1) {
        return true;
    }
    return false;
}
/////bfs-------------------///////////////
bool bfs(int si, int sj, int zone_num) {
    queue<pii> q;
    q.push({si, sj});
    visited[si][sj] = 1;
    zone[si][sj] = zone_num;
    char c = animal[si][sj];
    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int ii = di[d] + i;
            int jj = dj[d] + j;

            if (ii < 0 || ii >= n || jj < 0 || jj >= n || visited[ii][jj]) {
                continue;
            }
            visited[ii][jj] = 1;
            if (wallCheck(i, j, ii, jj)) {
                continue;
            }
            q.push({ii, jj});

            if (animal[ii][jj] == '.' || animal[ii][jj] == c) {
                zone[ii][jj] = zone_num;
                continue;
            }

            return false;
        }
    }

    return true;
}
//////solution-------------/////////////////////////////////////////////////////
bool solution() {
    memset(zone, 0, sizeof(zone));
    int zone_num = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (zone[i][j] != 0) {
                continue;
            }
            if (animal[i][j] == '.') {
                continue;
            }
            memset(visited, 0, sizeof(visited));
            if (!bfs(i, j, zone_num++)) {
                return false;
            }
        }
    }
    return true;
}
//////display--------------------------/////////////////////////////////////////////
void display() {
    makeLine();
    for (int i = 0; i < 4 * n + 3; i++) {
        cout << '#';
    }
    cout << '\n';
    for (int i = 0; i < 2 * n + 1; i++) {
        cout << '#';
        for (int j = 0; j < 4 * n + 1; j++) {
            cout << ij[i][j];
        }
        cout << "#\n";
    }
    for (int i = 0; i < 4 * n + 3; i++) {
        cout << '#';
    }
    cout << '\n';
}

///////dfs--------------------------------------------------------------///////////////////////////////////////////////
void dfs(int i, int j) {
    if (i == n && j == n) {
        if (solution()) {
            cout << "yes\n";
            display();
            exit(0);
        }
        return;
    }
    for (int d = 0; d < 4; d++) {
        int ii = i + di[d];
        int jj = j + dj[d];
        if (!in_range(ii, jj)) {
            continue;
        }
        vst[ii][jj] = 1;
        if (d == 0) {
            bound[2 * i + 1][2 * j] = 1;

        } else if (d == 1) {
            bound[2 * i][2 * j + 1] = 1;

        } else if (d == 2) {
            bound[2 * ii + 1][2 * jj] = 1;

        } else {
            bound[2 * ii][2 * jj + 1] = 1;
        }
        dfs(ii, jj);

        vst[ii][jj] = 0;
        if (d == 0) {
            bound[2 * i + 1][2 * j] = 0;
        } else if (d == 1) {
            bound[2 * i][2 * j + 1] = 0;
        } else if (d == 2) {
            bound[2 * ii + 1][2 * jj] = 0;
        } else {
            bound[2 * ii][2 * jj + 1] = 0;
        }
    }
}
//////////////main------------------------/////////////////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> animal[i];
        int tmp = 2;
        for (auto& c : animal[i]) {
            ij[i * 2 + 1][tmp] = c;
            tmp += 4;
        }
    }
    memset(bound, 0, sizeof(bound));
    memset(vst, 0, sizeof(vst));

    vst[0][0] = 1;
    dfs(0, 0);

    cout << "no";
    return 0;
}
