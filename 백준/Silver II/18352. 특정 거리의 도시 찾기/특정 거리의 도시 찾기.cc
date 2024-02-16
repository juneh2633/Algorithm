#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
int INF = 1e9;
const int MAX_N = 322222;
int n, m, k, x;

int dist[MAX_N];

vector<int> solution(int start, vector<pii> *graph) {
    fill(dist, dist + MAX_N, INF);
    priority_queue<pii> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int d, v;
        tie(d, v) = pq.top();
        d = d * (-1);
        pq.pop();
        if (dist[v] != d) {
            continue;
        }
        for (auto &&i : graph[v]) {
            int nv, w;
            tie(nv, w) = i;
            if (dist[nv] > dist[v] + w) {
                dist[nv] = dist[v] + w;
                pq.push({-dist[nv], nv});
            }
        }
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == k) {
            ans.push_back(i);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k >> x;
    vector<pii> graph[n + 1];
    vector<pii> graph_reverse[n + 1];
    while (m--) {
        int u, v, w;
        cin >> u >> v;
        graph[u].push_back({v, 1});
    }
    vector<int> ans = solution(x, graph);

    if (ans.size() == 0) {
        cout << "-1";
        return 0;
    }
    sort(ans.begin(), ans.end());

    for (auto &i : ans) {
        cout << i << '\n';
    }
}