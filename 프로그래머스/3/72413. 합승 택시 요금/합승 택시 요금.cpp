#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
const int INF = 10000001;


vector<pii> graph[333];
int distA[333];
int distB[333];
int distC[333];

void dijA(int start){
    fill(distA,distA+333,INF);
    priority_queue<pii> pq;
    pq.push({0, start});
    distA[start] = 0;
    
    while (!pq.empty()) {
        int d, v;
        tie(d, v) = pq.top();
        d = d * (-1);
        pq.pop();
        if (distA[v] != d) {
            continue;
        }

        for (auto &i : graph[v]) {
            int w, target;
            tie(target, w) = i;
            if (distA[target] > distA[v] + w) {
                distA[target] = distA[v] + w;
                pq.push({-distA[target], target});
            }
        }

    }
}

void dijB(int start){
    fill(distB,distB+333,INF);
    priority_queue<pii> pq;
    pq.push({0, start});
    distB[start] = 0;
    
    while (!pq.empty()) {
        int d, v;
        tie(d, v) = pq.top();
        d = d * (-1);
        pq.pop();
        if (distB[v] != d) {
            continue;
        }

        for (auto &i : graph[v]) {
            int w, target;
            tie(target, w) = i;
            if (distB[target] > distB[v] + w) {
                distB[target] = distB[v] + w;
                pq.push({-distB[target], target});
            }
        }

    }
}
void dijC(int start){
    fill(distC,distC+333,INF);

    priority_queue<pii> pq;
    pq.push({0, start});
    distC[start] = 0;
    
    while (!pq.empty()) {
        int d, v;
        tie(d, v) = pq.top();
        d = d * (-1);
        pq.pop();
        if (distC[v] != d) {
            continue;
        }

        for (auto &i : graph[v]) {
            int w, target;
            tie(target, w) = i;
            if (distC[target] > distC[v] + w) {
                distC[target] = distC[v] + w;
                pq.push({-distC[target], target});
            }
        }

    }
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;

    for(auto &v:fares){
        graph[v[0]].push_back({v[1],v[2]});
        graph[v[1]].push_back({v[0],v[2]});
    }
    dijA(a);
    dijB(b);
    dijC(s);
    for(int i=1; i<=n;i++){
        answer=min(answer,distA[i]+distB[i]+distC[i]);
    }
    return answer;
}