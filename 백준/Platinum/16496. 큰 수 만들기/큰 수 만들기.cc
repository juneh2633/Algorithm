#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const ll N = 1e5 + 1;
const ll MAX = 1e9;
ll n = 0;
bool compare(const string &a, const string &b) {
    if (a == b) {
        return false;
    }
    string x = a + b;
    string y = b + a;
    return x > y;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<string> s(n);
    for (auto &i : s) {
        cin >> i;
    }
    sort(s.begin(), s.end(), compare);
    if (s[0] == "0" && s[n - 1] == "0") {
        cout << "0";
        return 0;
    }
    for (auto &i : s) {
        cout << i;
    }
}
// 1211
// 121
// 121 1211