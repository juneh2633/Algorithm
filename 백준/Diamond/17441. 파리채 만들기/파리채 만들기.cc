#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;
const ll N = 1e5 + 1;
const ll MAX = 1e9;
int n;

double cross(pdd a, pdd b, pdd c) {
    double x1 = b.first - a.first;
    double x2 = c.first - a.first;
    double y1 = b.second - a.second;
    double y2 = c.second - a.second;
    return (x1 * y2 - x2 * y1) / 2;
}

// clang-format off
double tpow(double a) { 
    return a * a * a;
}
double pow(double a) { 
    return a * a; 
}
/// ...
// clang-format on

double area(vector<pdd> &v) {
    pdd c = v[0];
    double sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += cross(c, v[i], v[i + 1]);
    }
    return abs(sum);
}
double fomula_1(double x1, double x2, double y1, double y2) {
    double sum = 0;
    // sum += (y2 - y1) * (tpow(x1) + pow(x1) * x2 + x1 * pow(x2) + tpow(x2));
    // sum = sum - (x2 - x1) * (tpow(y1) + pow(y1) * y2 + y1 * pow(y2) +
    // tpow(y2));
    sum = (x1 * y2 - x2 * y1) *
          (pow(x1) + x1 * x2 + pow(x2) + pow(y1) + y1 * y2 + pow(y2));
    return sum;
}
double fomula_2(double x1, double x2, double y1, double y2) {
    double sum = 0;
    sum = (y2 - y1) * (pow(x1) + x1 * x2 + pow(x2));

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<pdd> v(n);
    for (auto &i : v) {
        double x, y;
        cin >> x >> y;
        i = {x, y};
    }

    double A = area(v);
    double sum_1 = 0;
    double sum_2 = 0;
    double sum_3 = 0;
    for (int i = 1; i < n; i++) {
        double x1 = v[i - 1].first;
        double y1 = v[i - 1].second;
        double x2 = v[i].first;
        double y2 = v[i].second;
        sum_1 += fomula_1(x1, x2, y1, y2) / 12;
        sum_2 += fomula_2(x1, x2, y1, y2) / 6;
        sum_3 += fomula_2(y1, y2, x1, x2) / 6;
    }
    double x1 = v[n - 1].first;
    double y1 = v[n - 1].second;
    double x2 = v[0].first;
    double y2 = v[0].second;
    sum_1 += fomula_1(x1, x2, y1, y2) / 12;
    sum_2 += fomula_2(x1, x2, y1, y2) / 6;
    sum_3 += fomula_2(y1, y2, x1, x2) / 6;
    double ans = (A * sum_1 - pow(sum_2) - pow(sum_3)) * 2 / pow(A);
    cout << fixed;
    cout.precision(10);
    cout << ans;
}
