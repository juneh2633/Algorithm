#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int num = n;
    deque<int> dq;
    stack<int> cmd;
    for (ll i = 0; i < n; i++) {
        int a;
        cin >> a;
        cmd.push(a);
    }
    for (ll i = 1; i <= n; i++) {
        int a = cmd.top();
        cmd.pop();
        if (a == 1) {
            dq.push_front(i);
        } else if (a == 2) {
            int tmp = dq.front();
            dq.pop_front();
            dq.push_front(i);
            dq.push_front(tmp);
        } else {
            dq.push_back(i);
        }
        num--;
    }
    for (auto &i : dq) {
        cout << i << " ";
    }
    return 0;
}
