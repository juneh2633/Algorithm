#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll segTree[4000001];
ll n, m, k;
/*
    3 7 5 1 4 8 2 5를 넣는다면
    n = 8
    3을 넣어보자
    update(1, 1, 8, 1, 3);
        update(2, 1, 4, 1, 3);
            =>update(4, 1, 2, 1, 3);
                => update(8,1,1,1,3) save
                =>update(9,2,2,1,3) return
            =>update(5 3, 4, 1, 3); return
        update(3, 5, 8, 1, 3);return
    seg[1]=seg[2]+seg[3]


    01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16
    3  3  ,  3  ,  ,  ,  3

    7을 넣어보자
    update(1, 1, 8, 2, 7);
        update(2, 1, 4, 2, 7);
            =>update(4, 1, 2, 2, 7);
                =>update(8, 1, 1 ,2 ,7);
                =>update(9, 2, 2, 2, 7); save
            =>update(5, 3, 4, 2, 7);
        update(3, 5, 8, 2, 3);return

    01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16
    7  7  ,  7  ,  ,  ,  ,  7
    =>
    01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16
    10 10  , 10 ,  ,  ,  3  7


    => 5를 넣는다면
    update(1, 1, 8, 3, 5)
    01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16
    5  5  ,  ,  5  ,  ,  ,  ,  5
    01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16
    15 15  , 10 5  ,  ,  3  7  5

*/
void update(ll ptr, ll s, ll e, ll i, ll x) {
    if (s > i || e < i) return;  // i가 보고있는 구간에 없으면 리턴

    if (s == e) {
        segTree[ptr] = x;
        return;
    }

    update(ptr * 2, s, (s + e) / 2, i, x);
    update(ptr * 2 + 1, (s + e) / 2 + 1, e, i, x);

    segTree[ptr] = segTree[ptr * 2] + segTree[ptr * 2 + 1];
}

ll getVal(ll ptr, ll s, ll e, ll l, ll r) {
    if (r < s || e < l) return 0;

    if (l <= s && e <= r) {
        return segTree[ptr];
    }
    return getVal(ptr * 2, s, (s + e) / 2, l, r) +
           getVal(ptr * 2 + 1, (s + e) / 2 + 1, e, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    for (ll i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        update(1, 1, n, i, x);
    }
    for (ll i = 0; i < m + k; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, 1, n, b, c);
        } else if (a == 2) {
            cout << getVal(1, 1, n, b, c) << '\n';
        }
    }
    return 0;
}
