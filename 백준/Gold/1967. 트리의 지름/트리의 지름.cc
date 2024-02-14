#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
vector<vector<pii>> graph(111111);
bool vst[11111] = {
    0,
};
int ans = 0;
int max_dist = 0;
int max_target = 0;
void solution(int target, int dist) {
    if (vst[target]) {
        return;
    }
    vst[target] = true;
    if (max_dist < dist) {
        max_dist = dist;
        max_target = target;
    }
    for (auto &i : graph[target]) {
        solution(i.first, dist + i.second);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a;
        cin >> a;
        int target, weight;

        cin >> target >> weight;

        graph[a].push_back({target, weight});
        graph[target].push_back({a, weight});
    }

    solution(1, 0);
    memset(vst, 0, sizeof(vst));

    solution(max_target, 0);
    cout << max_dist;
}