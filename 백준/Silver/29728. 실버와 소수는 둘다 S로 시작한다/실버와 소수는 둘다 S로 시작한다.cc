#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 5000000;
bool isNotPrime[N];

void primeCheck(int n) {
    for (int i = 2; i * i <= n; i++) {
        for (int j = i * i; j <= n; j += i) {
            isNotPrime[j] = 1;
        }
    }
    isNotPrime[2] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(isNotPrime, 0, sizeof(isNotPrime));
    int n;
    cin >> n;
    deque<bool> dq;
    bool rev = 0;
    primeCheck(n);
    // b ==1 , s==0
    dq.push_back(1);
    for (int i = 2; i <= n; i++) {
        if (isNotPrime[i]) {
            if (!rev) {
                dq.push_back(1);
                continue;
            }
            dq.push_front(1);
            continue;
        }
        if (!rev) {
            if (dq.back()) {
                dq.pop_back();
                dq.push_back(0);
                dq.push_back(0);
            } else {
                dq.push_back(0);
                rev = 1;
            }
        } else {
            if (dq.front()) {
                dq.pop_front();
                dq.push_front(0);
                dq.push_front(0);
            } else {
                dq.push_front(0);
                rev = 0;
            }
        }
    }
    int ansB = 0;
    for (auto &i : dq) {
        if (i) {
            ansB++;
        }
    }
    cout << ansB << " " << n - ansB;
}