#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
int INF = 1e9;
const int MAX_N = 222222;
int n, m, x;

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
    int ans = 0;
    vector<int> dist_v(n + 1);
    for (int i = 1; i <= n; i++) {
        dist_v[i] = dist[i];
    }
    return dist_v;
}
int is_distance(int start, int end, vector<pii> *graph) {
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
    return dist[end];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> x;
    vector<pii> graph[n + 1];
    vector<pii> graph_reverse[n + 1];
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[v].push_back({u, w});
    }
    vector<int> back = solution(x, graph);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i == x) {
            continue;
        }

        ans = max(ans, back[i] + is_distance(i, x, graph));
    }
    cout << ans;
}