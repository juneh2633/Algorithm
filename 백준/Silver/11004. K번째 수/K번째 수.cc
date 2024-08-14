#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &x : v) {
        cin >> x;
    }
    sort(v.begin(), v.end());
    cout << v[k - 1];
}