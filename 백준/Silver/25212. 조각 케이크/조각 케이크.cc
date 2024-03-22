#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const ll N = 1e5 + 1;
const ll MAX = 1e9;
int n;
int ans = 0;
double v[11];
void solution(int cur, double sum) {
    if (cur == n) {
        if (sum >= 0.99 && sum <= 1.01) {
            ans++;
        }
        return;
    }
    solution(cur + 1, sum + (double)(1 / v[cur + 1]));
    solution(cur + 1, sum);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    solution(0, (double)(1 / v[0]));
    solution(0, (double)(0));
    cout << ans;
}
