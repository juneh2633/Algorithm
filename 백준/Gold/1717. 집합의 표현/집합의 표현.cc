#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
int par[N];
int height[N];
int n, m;

int getPar(int a) {
    if (par[a] == -1) {
        return a;
    }
    return par[a] = getPar(par[a]);
}

void merge(int a, int b) {
    a = getPar(a);
    b = getPar(b);
    if (a == b) return;
    if (height[a] > height[b]) {
        par[b] = a;
    } else if (height[a] < height[b]) {
        par[a] = b;
    } else {
        par[a] = b;
        height[b]++;
    }
}

void solution() {
    memset(par, -1, sizeof(par));
    memset(height, 0, sizeof(height));
    cin >> n >> m;
    while (m--) {
        int cmd, a, b;
        cin >> cmd >> a >> b;
        if (cmd == 0) {
            merge(a, b);
        } else {
            if (getPar(a) == getPar(b)) {
                cout << "YES";
            } else {
                cout << "NO";
            }
            cout << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();
}