#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
const int INF = 10000001;

vector<pii> graph[333];
vector<vector<int>> dist(3, vector<int>(333, INF)); // 0 for A, 1 for B, 2 for C

void dijkstra(int start, int idx){
    fill(dist[idx].begin(), dist[idx].end(), INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    dist[idx][start] = 0;
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (dist[idx][v] < d) continue;

        for (auto &edge : graph[v]) {
            int target = edge.first;
            int w = edge.second;
            if (dist[idx][target] > dist[idx][v] + w) {
                dist[idx][target] = dist[idx][v] + w;
                pq.push({dist[idx][target], target});
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;

    for(auto &v : fares){
        graph[v[0]].push_back({v[1], v[2]});
        graph[v[1]].push_back({v[0], v[2]});
    }
    dijkstra(a, 0);
    dijkstra(b, 1);
    dijkstra(s, 2);
    for(int i = 1; i <= n; i++){
        answer = min(answer, dist[0][i] + dist[1][i] + dist[2][i]);
    }
    return answer;
}
