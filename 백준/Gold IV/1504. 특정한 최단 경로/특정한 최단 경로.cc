#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
int INF = 1e8;
const int MAX_N = 801;
int n, m;

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
    vector<int> dist_v(n + 1);
    for (int i = 1; i <= n; i++) {
        dist_v[i] = dist[i];
    }
    return dist_v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    vector<pii> graph[n + 1];
    vector<pii> graph_reverse[n + 1];
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    int p, q;
    cin >> p >> q;
    vector<int> oTo = solution(1, graph);
    vector<int> pTo = solution(p, graph);
    vector<int> qTo = solution(q, graph);
    int oToN, oToP, oToQ, pToQ, qToP, pToN, qToN;

    oToP = oTo[p];
    oToQ = oTo[q];
    pToQ = pTo[q];
    qToP = qTo[p];
    pToN = pTo[n];
    qToN = qTo[n];
    int ans = INF;
    int side[4] = {
        oToP + pToQ + qToN,
        oToQ + qToP + pToN,
        oToP + pToQ + qToP + pToN,
        oToQ + qToP + pToQ + qToN,
    };
    for (int i = 0; i < 4; i++) {
        ans = min(ans, side[i]);
    }
    if (ans >= INF) {
        cout << "-1";
    } else {
        cout << ans;
    }
}

// 1 p q n
// 1 q p n
// 1 p q p n
// 1 q p q n
