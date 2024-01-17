#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 0;
    while (t++ < 10) {
        cout << "#" << t;
        int n, m;
        cin >> n;
        list<int> v;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            v.push_back(a);
        }
        cin >> m;
        while (m--) {
            char cmd;
            int x, y;

            cin >> cmd;
            if (cmd == 'I') {
                cin >> x >> y;
                auto iter = next(v.begin(), x);
                list<int> sl;
                while (y--) {
                    int a;
                    cin >> a;
                    sl.push_back(a);
                }
                v.insert(iter, sl.begin(), sl.end());

            } else if (cmd == 'D') {
                cin >> x >> y;
                auto start = next(v.begin(), x);
                auto end = next(v.begin(), x + y);
                v.erase(start, end);
            } else {
                cin >> y;
                list<int> sl;
                while (y--) {
                    int a;
                    cin >> a;
                    sl.push_back(a);
                }
            }
        }
        for (int i = 0; i < 10; i++) {
            cout << " " << v.front();
            v.pop_front();
        }
        cout << '\n';
    }
}