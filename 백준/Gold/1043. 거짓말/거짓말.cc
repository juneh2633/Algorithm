#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;

int n, m;
bool know_arr[55] = {
    0,
};
bool is_friend[55][55] = {
    0,
};
int party[55][55] = {
    0,
};
int party_size[55] = {
    0,
};

bool is_know_truth(int a) {
    queue<int> q;
    vector<int> total;
    q.push(a);
    int vst[55] = {
        0,
    };

    bool check = 0;
    while (!q.empty()) {
        int tmp = q.front();
        total.push_back(tmp);
        q.pop();
        if (know_arr[tmp]) {
            check = 1;
        }
        for (int i = 1; i <= n; i++) {
            if (i == tmp) {
                continue;
            }
            if (is_friend[tmp][i] && !vst[i]) {
                vst[i] = true;
                q.push(i);
            }
        }
    }

    if (check == 1) {
        for (auto& i : total) {
            know_arr[i] = true;
        }
    }
    return check;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(know_arr, false, sizeof(know_arr));
    cin >> n >> m;
    int k;
    cin >> k;
    vector<int> know(k);
    for (auto& i : know) {
        cin >> i;
        know_arr[i] = true;
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            int ii = know[i];
            int jj = know[j];
            is_friend[ii][jj] = true;
            is_friend[jj][ii] = true;
        }
    }

    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        party_size[i] = a;
        for (int j = 0; j < a; j++) {
            cin >> party[i][j];
        }
        for (int x = 0; x < a; x++) {
            for (int y = 0; y < a; y++) {
                is_friend[party[i][x]][party[i][y]] = true;
                is_friend[party[i][y]][party[i][x]] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < party_size[i]; j++) {
            if (!is_know_truth(party[i][j])) {
                ans++;
                break;
            }
        }
    }
    cout << ans;
}
