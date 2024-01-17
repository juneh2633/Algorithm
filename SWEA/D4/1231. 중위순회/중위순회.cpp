#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int tree[101][3];
char element[101];
void solution(int n) {
    if (n <= 0) return;

    solution(tree[n][1]);
    tree[n][1] = 0;
    cout << element[n];
    solution(tree[n][2]);
    tree[n][2] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 10;
    for (int t = 1; t <= T; t++) {
        int n;

        cin >> n;
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        for (int i = 1; i <= n; i++) {
            string s;

            getline(cin, s);
            istringstream iss(s);
            string ss;
            int tmp = 0;
            while (iss >> ss) {
                if (!ss.empty() && isdigit(ss[0])) {
                    tree[i][tmp++] = stoi(ss);
                } else if (!ss.empty()) {
                    element[i] = ss[0];
                }
            }
        }

        cout << "#" << t << " ";
        solution(1);
        cout << '\n';
    }
}
