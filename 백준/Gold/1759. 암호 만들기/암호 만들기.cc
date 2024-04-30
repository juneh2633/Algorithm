#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int l, c;
vector<char> ch;
char arr[17];
char aeiou[5] = {'a', 'e', 'i', 'o', 'u'};
vector<string> ans;
void solution(int target, int cur) {
    if (target == l) {
        string s = "";
        int cnt = 0;
        for (int i = 0; i < l; i++) {
            for (int d = 0; d < 5; d++) {
                if (arr[i] == aeiou[d]) {
                    cnt++;
                    continue;
                }
            }
            s += arr[i];
        }
        if (cnt >= 1 && (l - cnt) >= 2) {
            ans.push_back(s);
        }
        return;
    }

    for (int i = cur; i < c; i++) {
        arr[target] = ch[i];
        solution(target + 1, i + 1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> l >> c;
    ch.resize(c);
    for (auto &i : ch) {
        cin >> i;
    }
    sort(ch.begin(), ch.end());

    solution(0, 0);
    for (auto &i : ans) {
        cout << i << '\n';
    }
}