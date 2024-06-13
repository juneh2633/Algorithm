#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            mp[1] = 1;
            continue;
        }
        if (mp.find(a - 1) == mp.end()) {
            mp[a] = 1;
            continue;
        }
        mp.erase(a - 1);
        mp[a] = 1;
    }
    cout << mp.size() - 1;
}