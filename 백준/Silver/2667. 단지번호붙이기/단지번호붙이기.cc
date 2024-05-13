#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int di[4] = {1, 0, -1, 0};
const int dj[4] = {0, 1, 0, -1};

int n;
int ij[25][25];
bool isVisited[25][25];
vector<int> answerList;

bool isRange(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= n) {
        return false;
    }
    if (isVisited[i][j] || !ij[i][j]) {
        return false;
    }
    return true;
}

void bfs(int startI, int startJ) {
    queue<pii> q;
    q.push({startI, startJ});
    isVisited[startI][startJ] = 1;

    int cnt = 1;
    while (!q.empty()) {
        int curI, curJ;
        tie(curI, curJ) = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int targetI = curI + di[d];
            int targetJ = curJ + dj[d];

            if (!isRange(targetI, targetJ)) {
                continue;
            }

            isVisited[targetI][targetJ] = 1;
            q.push({targetI, targetJ});
            cnt++;
        }
    }

    answerList.push_back(cnt);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            ij[i][j] = s[j] - '0';
        }
    }
    memset(isVisited, 0, sizeof isVisited);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!isRange(i, j)) {
                continue;
            }
            bfs(i, j);
        }
    }
    sort(answerList.begin(), answerList.end());

    cout << answerList.size() << '\n';
    for (int &answer : answerList) {
        cout << answer << '\n';
    }
}