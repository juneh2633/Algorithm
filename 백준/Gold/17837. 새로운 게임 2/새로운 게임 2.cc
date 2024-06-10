#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int di[5] = {0, 0, 0, -1, 1};
int dj[5] = {0, 1, -1, 0, 0};
int dChange[5] = {0, 2, 1, 4, 3};
int n, k;

struct Piece {
    int number;
    int i;
    int j;
    int d;
    int bottom;
};

int ij[15][15];
int color[15][15];
Piece p[11];
deque<int> upper[11];

bool inRange(int i, int j) {
    if (i < 0 || i >= n) {
        return false;
    }
    if (j < 0 || j >= n) {
        return false;
    }
    if (color[i][j] == 2) {
        return false;
    }
    return true;
}
bool ansCheck() {
    for (int t = 1; t < 11; t++) {
        if (upper[t].size() >= 3) {
            return true;
        }
    }
    return false;
}

void moveWithUpper_noPiece(int target, int i, int j) {
    int bottom = p[target].bottom;
    p[target].i = i;
    p[target].j = j;

    if (bottom == 0) {
        for (auto &cur : upper[target]) {
            p[cur].i = i;
            p[cur].j = j;
        }

        return;
    }


    while (!upper[bottom].empty()) {
        int cur = upper[bottom].back();
        p[cur].bottom = target;
        p[cur].i = i;
        p[cur].j = j;
        upper[bottom].pop_back();
        if (cur == target) {
            p[cur].bottom = 0;
            break;
        }
        upper[target].push_front(cur);
    }
}


void moveWithUpper_Piece(int target, int newBottom, int i, int j) {
    int oldBottom = p[target].bottom;
    if (oldBottom == 0) {
        oldBottom = target;
    }
    p[target].bottom = newBottom;
    p[target].i = i;
    p[target].j = j;
    upper[newBottom].push_back(target);
    stack<int> intoNewBottom;

    while (!upper[oldBottom].empty()) {
        int cur = upper[oldBottom].back();
        p[cur].bottom = newBottom;
        p[cur].i = i;
        p[cur].j = j;
        upper[oldBottom].pop_back();
        if (cur == target) {
            break;
        }
        intoNewBottom.push(cur);
    }

    while (!intoNewBottom.empty()) {
        upper[newBottom].push_back(intoNewBottom.top());
        intoNewBottom.pop();
    }
}

int reverseUpper(int target) {
    int curBottom = p[target].bottom;

    if (curBottom == 0) {
        if (upper[target].empty()) {
            return target;
        }
        int newBottom = upper[target].back();

        upper[target].pop_back();
        p[newBottom].bottom = 0;
        queue<int> q;
        while (!upper[target].empty()) {
            int cur = upper[target].back();
            upper[target].pop_back();
            p[cur].bottom = newBottom;
            q.push(cur);
        }
        p[target].bottom = newBottom;
        q.push(target);
        while (!q.empty()) {
            upper[newBottom].push_back(q.front());
            q.pop();
        }
        return newBottom;
    }


    queue<int> q;
    int newTarget = upper[curBottom].back();
    p[target].bottom = curBottom;
    while (!upper[curBottom].empty()) {
        int cur = upper[curBottom].back();
        upper[curBottom].pop_back();
        q.push(cur);

        if (cur == target) {
            break;
        }
    }
    while (!q.empty()) {
        upper[curBottom].push_back(q.front());
        q.pop();
    }

    return newTarget;
}

void move(int num) {
    int d = p[num].d;
    int i = p[num].i;
    int j = p[num].j;
    int ii = i + di[d];
    int jj = j + dj[d];
    if (!inRange(ii, jj)) {
        p[num].d = dChange[d];
        ii = i + di[p[num].d];
        jj = j + dj[p[num].d];
        if (!inRange(ii, jj)) {
            return;
        }
    }

    if (ij[i][j] == num) {
        ij[i][j] = 0;
    }

    if (color[ii][jj] == 1) {
        num = reverseUpper(num);
    }

    if (ij[ii][jj] == 0) {
        ij[ii][jj] = num;
        moveWithUpper_noPiece(num, ii, jj);
    } else {
        moveWithUpper_Piece(num, ij[ii][jj], ii, jj);
    }
}

void solution() {
    int ans = 1;
    while (ans <= 1000) {
        for (int x = 1; x <= k; x++) {
            move(x);
            if (ansCheck()) {
                cout << ans;
                return;
            }
        }
        ans++;
    }

    cout << "-1";
}

void input() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> color[i][j];
        }
    }
    for (int x = 1; x <= k; x++) {
        int i, j, d;
        cin >> i >> j >> d;

        p[x] = {x, i - 1, j - 1, d, 0};
        ij[i - 1][j - 1] = x;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    solution();
}