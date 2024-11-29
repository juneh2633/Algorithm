#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n;
queue<int> q;
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        q.push(a);
    }
}

void solution() {
    stack<int> st;
    int cur = 1;
    while (!q.empty()) {
        if (q.front() == cur) {
            q.pop();
            cur++;
            continue;
        }
        if (!st.empty() && st.top() == cur) {
            st.pop();
            cur++;
            continue;
        }
        st.push(q.front());
        q.pop();
    }

    while (!st.empty()) {
        if (st.top() == cur) {
            st.pop();
            cur++;
            continue;
        } else {
            break;
        }
    }
    if (cur <= n) {
        cout << "Sad";
    } else {
        cout << "Nice";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solution();
}