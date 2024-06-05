#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int n, m, k;
int INF = 10000001;
int MAX_N = 1111;

vector<pii> graph[1111];

priority_queue<int> ans[1111];
void djk() {
    priority_queue<pii> pq;
    ans[1].push(0);
    pq.push({0, 1});

    while (!pq.empty()) {
        int d, v;
        tie(d, v) = pq.top();
        d = d * (-1);
        pq.pop();

        for (auto &i : graph[v]) {
            int w, target;
            tie(target, w) = i;
            int tmp = d + w;

            if (ans[target].size() < k) {
                ans[target].push(tmp);
                pq.push({-tmp, target});

            } else {
                if (ans[target].top() > tmp) {
                    ans[target].pop();
                    ans[target].push(tmp);
                    pq.push({-tmp, target});
                }
            }
        }
        //
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    djk();
    for (int i = 1; i <= n; i++) {
        if (ans[i].size() != k) {
            cout << "-1\n";
            continue;
        }

        cout << ans[i].top() << '\n';
    }
}