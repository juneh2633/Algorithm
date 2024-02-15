#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
int INF = 155555555;
int MAX_N = 222222;

vector<pii> graph[222222];
int dist[222222];
int n, m;
void solution(int start, int end) {
    fill(dist, dist + 222222, INF);
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

        for (auto &i : graph[v]) {
            int w, target;
            tie(target, w) = i;
            if (dist[target] > dist[v] + w) {
                dist[target] = dist[v] + w;
                pq.push({-dist[target], target});
            }
        }
        //
    }
    cout << dist[end];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;

        graph[x].push_back({y, w});
    }
    int a, b;
    cin >> a >> b;
    solution(a, b);
}