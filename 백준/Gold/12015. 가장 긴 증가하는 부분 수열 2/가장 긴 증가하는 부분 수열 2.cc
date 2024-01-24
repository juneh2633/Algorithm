#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;

vector<int> a, ans;

int idx_bsearch(int k) {
    int l = 0, r = ans.size() - 1, mid;

    while (l < r) {
        mid = l + (r - l) / 2;

        if (ans[mid] >= k)
            r = mid;
        else
            l = mid + 1;
    }

    return r;
}

int main(void) {
    int n, t, idx;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        a.push_back(t);
    }
    ans.push_back(a.front());

    for (int i = 1; i < n; i++) {
        if (a[i] > ans.back())
            ans.push_back(a[i]);
        else {
            idx = idx_bsearch(a[i]);
            ans[idx] = a[i];
        }
    }
    cout << ans.size();

    return 0;
}
