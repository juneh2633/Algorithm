#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int n;
int di[4] = {-1, 0, 0, 1};
int dj[4] = {0, -1, 1, 0};
int ij[22][22];
int debug[22][22];
int growth[9] = {0, 0, 2, 5, 9, 14, 20, 28, 99999999};
int leftFood;
struct dij {
    int distance, i, j;

    bool operator<(const dij &other) const {
        if (distance == other.distance) {
            if (i == other.i) {
                return j > other.j;
            }
            return i > other.i;
        }
        return distance > other.distance;
    }
};
void debugPrint() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << debug[i][j] << "  ";
        }
        cout << '\n';
    }
}
bool inRange(int i, int j, int size) {
    if (i < 0 || i >= n) {
        return false;
    }
    if (j < 0 || j >= n) {
        return false;
    }

    if (size < ij[i][j]) {
        return false;
    }
    return true;
}

dij bfs(int si, int sj, int size) {
    queue<dij> q;
    priority_queue<dij> fish;
    q.push({0, si, sj});
    int visited[22][22];
    memset(visited, 0, sizeof(visited));
    while (!q.empty()) {
        dij cur = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int ii = cur.i + di[d];
            int jj = cur.j + dj[d];

            if (!inRange(ii, jj, size)) {
                continue;
            }
            if (visited[ii][jj]) {
                continue;
            }
            visited[ii][jj] = 1;
            if (ij[ii][jj] != 0 && ij[ii][jj] != size) {
                fish.push({cur.distance + 1, ii, jj});
                continue;
            }

            q.push({cur.distance + 1, ii, jj});
        }
    }
    if (fish.empty()) {
        return {-1, si, sj};
    }
    ij[fish.top().i][fish.top().j] = 0;
    return fish.top();
}

void solution(int si, int sj) {
    int tmp = 1;
    int size = 2;
    int foodCnt = 0;
    int turn = 0;
    int curI = si;
    int curJ = sj;
    while (1) {
        dij nextSharkSate = bfs(curI, curJ, size);
        if (nextSharkSate.distance == -1) {
            break;
        }
        turn += nextSharkSate.distance;
        curI = nextSharkSate.i;
        curJ = nextSharkSate.j;
        // cout << curI << " " << curJ << " :" << nextSharkSate.distance <<
        // '\n';
        debug[curI][curJ] = tmp++;
        foodCnt++;
        if (growth[size] <= foodCnt) {
            size++;
        }
        if (foodCnt >= leftFood) {
            break;
        }
    }
    cout << turn;
    // cout << '\n';
    // debugPrint();
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int si, sj;
    cin >> n;
    leftFood = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ij[i][j];
            if (ij[i][j] == 9) {
                si = i;
                sj = j;
                ij[i][j] = 0;
            } else {
                leftFood++;
            }
        }
    }
    solution(si, sj);
}