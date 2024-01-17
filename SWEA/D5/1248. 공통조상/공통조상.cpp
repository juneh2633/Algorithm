#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n;
int x, y;
int tree[10001][2] = {
    0,
};
int subtree_size[10001] = {
    0,
};
vector<int> vx;
vector<int> vy;
int v_check;
int ans = 0;

void solution(int idx, vector<int>& q) {
    if (idx <= 0) return;

    if (idx == x) {
        vx = q;
        v_check++;
    }
    if (idx == y) {
        vy = q;
        v_check++;
    }
    if (v_check == 2) {
        int minSize = min(vx.size(), vy.size());
        int tmp = 0;
        while (tmp < minSize) {
            if (vx[tmp] != vy[tmp]) break; 
            tmp++;
        }
       tmp--;

        ans = vx[tmp];
        
        v_check=3;
    }
    if (tree[idx][0] != 0) {
        q.push_back(tree[idx][0]);
        solution(tree[idx][0], q);
        q.pop_back();
        subtree_size[idx] += subtree_size[tree[idx][0]];
    }
    if (tree[idx][1] != 0) {
        q.push_back(tree[idx][1]);
        solution(tree[idx][1], q);
        q.pop_back();
        subtree_size[idx] += subtree_size[tree[idx][1]];
    }

    subtree_size[idx]++;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int v, e;
        cin >> v >> e >> x >> y;
        bool check[10001] = {
            false,
        };
        memset(tree, 0, sizeof(tree));
        memset(subtree_size, 0, sizeof(subtree_size));
        v_check = 0;
        for (int i = 1; i <= e; i++) {
            int a, b;
            cin >> a >> b;
            if (!check[a]) {
                tree[a][0] = b;
                check[a] = true;
            } else {
                tree[a][1] = b;
            }
        }
        vector<int> vv;
        vv.push_back(1);
       solution(1, vv);

       	cout << "#" << t << " " << ans << " " << subtree_size[ans] << '\n';
        vx.clear();
        vy.clear();
    }
    return 0;
}