#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
void solution(int x, vector<vector<int>>& relation, vector<bool>& visited) {
    queue<int> q;
    q.push(x);

    while (!q.empty()) {
        int xx = q.front();
        q.pop();
        for (auto& i : relation[xx]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int ans = 0;
        cin >> n >> m;
        vector<vector<int>> relation(n + 1);
        vector<bool> visited(n + 1, false);
        while (m--) {
            int a, b;
            cin >> a >> b;
            relation[a].push_back(b);
            relation[b].push_back(a);
        }
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                solution(i, relation, visited);
                ans++;
            }
        }
        cout << "#" << t << " " << ans << '\n';
    }
    return 0;
}