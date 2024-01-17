#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n;
// struct tree {
//     int p;
//     double l, r;
// };
double tree[1001][3];
char element[1001];
int op(char cmd, double x, double y) {
    if (cmd == '+') {
        return x + y;
    } else if (cmd == '-') {
        return x - y;
    } else if (cmd == '/') {
        return x / y;
    }
    return x * y;
}
bool isOp(string s) {
    if (s == "+" || s == "-" || s == "*" || s == "/") return true;

    return false;
}
void solution(int x) {
    if (x <= 0 || element[x] == 'n') return;

    solution(tree[x][1]);
    solution(tree[x][2]);

    tree[x][0] =
        op(element[x], tree[(int)tree[x][1]][0], tree[(int)tree[x][2]][0]);

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 10;
    for (int t = 1; t <= T; t++) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            double trash;
            string s;
            cin >> trash;
            cin >> s;
            if (isOp(s)) {
                element[i] = s[0];
                cin >> tree[i][1] >> tree[i][2];
            } else {
                tree[i][0] = stoi(s);
                element[i] = 'n';
            }
        }
        solution(1);

        cout << "#" << t << " " << (int)tree[1][0] << '\n';
    }
    return 0;
}