#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

ll _pow(ll x, ll p) {
	ll ret = 1, piv = x;
	while (p) {
		if (p & 1) ret = ret * piv % MOD;
		piv = piv * piv % MOD;
		p >>= 1;
	}
	return ret;
}
vector<int> berlekamp_massey(vector<int> x) {
	vector<int> ls, cur;
	int lf, ld;
	for (int i = 0; i < x.size(); i++) {
		ll t = 0;
		for (int j = 0; j < cur.size(); j++) {
			t = (t + 1ll * x[i - j - 1] * cur[j]) % MOD;
		}
		if ((t - x[i]) % MOD == 0) continue;
		if (cur.empty()) {
			cur.resize(i + 1);
			lf = i;
			ld = (t - x[i]) % MOD;
			continue;
		}
		ll k = -(x[i] - t) * _pow(ld, MOD - 2) % MOD;
		vector<int> c(i - lf - 1);
		c.push_back(k);
		for (auto& j : ls) c.push_back(-j * k % MOD);
		if (c.size() < cur.size()) c.resize(cur.size());
		for (int j = 0; j < cur.size(); j++) {
			c[j] = (c[j] + cur[j]) % MOD;
		}
		if (i - lf + (int)ls.size() >= (int)cur.size()) {
			tie(ls, lf, ld) = make_tuple(cur, i, (t - x[i]) % MOD);
		}
		cur = c;
	}
	for (auto& i : cur) i = (i % MOD + MOD) % MOD;
	return cur;
}
int get_nth(vector<int> rec, vector<int> dp, ll n) {
	int m = rec.size();
	vector<int> s(m), t(m);
	s[0] = 1;
	if (m != 1) t[1] = 1;
	else t[0] = rec[0];
	auto mul = [&rec](vector<int> v, vector<int> w) {
		int m = v.size();
		vector<int> t(2 * m);
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < m; k++) {
				t[j + k] += 1ll * v[j] * w[k] % MOD;
				if (t[j + k] >= MOD) t[j + k] -= MOD;
			}
		}
		for (int j = 2 * m - 1; j >= m; j--) {
			for (int k = 1; k <= m; k++) {
				t[j - k] += 1ll * t[j] * rec[k - 1] % MOD;
				if (t[j - k] >= MOD) t[j - k] -= MOD;
			}
		}
		t.resize(m);
		return t;
	};
	while (n) {
		if (n & 1) s = mul(s, t);
		t = mul(t, t);
		n >>= 1;
	}
	ll ret = 0;
	for (int i = 0; i < m; i++) ret += 1ll * s[i] * dp[i] % MOD;
	return ret % MOD;
}
int guess_nth_term(vector<int> x, ll n) {
	if (n < x.size()) return x[n];
	vector<int> v = berlekamp_massey(x);
	if (v.empty()) return 0;
	return get_nth(v, x, n);
}

int n, k, a[100][100], dp[250][100], ret[250];

int main() {
	fastio;
	cin >> n >> k;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
	for (int j = 0; j < n; j++) dp[0][j] = 1;
	for (int c = 1; c < 250; c++) {
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
			if (a[i][j]) dp[c][j] = (dp[c][j] + dp[c - 1][i]) % MOD;
		}
		for (int i = 0; i < n; i++) ret[c] = (ret[c] + dp[c][i]) % MOD;
	}
	vector<int> v;
	for (int c = 0; c < 250; c++) v.push_back(ret[c]);
	cout << guess_nth_term(v, k) << '\n';
}