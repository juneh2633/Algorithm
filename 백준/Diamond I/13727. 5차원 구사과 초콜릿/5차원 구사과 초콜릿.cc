#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
const ll mod = 1000000007;

ll ipow(ll x, ll p) {
    ll ret = 1, piv = x;
    while (p) {
        if (p & 1) ret = ret * piv % mod;
        piv = piv * piv % mod;
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
            t = (t + 1ll * x[i - j - 1] * cur[j]) % mod;
        }
        if ((t - x[i]) % mod == 0) continue;
        if (cur.empty()) {
            cur.resize(i + 1);
            lf = i;
            ld = (t - x[i]) % mod;
            continue;
        }
        ll k = -(x[i] - t) * ipow(ld, mod - 2) % mod;
        vector<int> c(i - lf - 1);
        c.push_back(k);
        for (auto &j : ls) c.push_back(-j * k % mod);
        if (c.size() < cur.size()) c.resize(cur.size());
        for (int j = 0; j < cur.size(); j++) {
            c[j] = (c[j] + cur[j]) % mod;
        }
        if (i - lf + (int)ls.size() >= (int)cur.size()) {
            tie(ls, lf, ld) = make_tuple(cur, i, (t - x[i]) % mod);
        }
        cur = c;
    }
    for (auto &i : cur) i = (i % mod + mod) % mod;
    return cur;
}
int get_nth(vector<int> rec, vector<int> dp, ll n) {
    int m = rec.size();
    vector<int> s(m), t(m);
    s[0] = 1;
    if (m != 1)
        t[1] = 1;
    else
        t[0] = rec[0];
    auto mul = [&rec](vector<int> v, vector<int> w) {
        int m = v.size();
        vector<int> t(2 * m);
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                t[j + k] += 1ll * v[j] * w[k] % mod;
                if (t[j + k] >= mod) t[j + k] -= mod;
            }
        }
        for (int j = 2 * m - 1; j >= m; j--) {
            for (int k = 1; k <= m; k++) {
                t[j - k] += 1ll * t[j] * rec[k - 1] % mod;
                if (t[j - k] >= mod) t[j - k] -= mod;
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
    for (int i = 0; i < m; i++) ret += 1ll * s[i] * dp[i] % mod;
    return ret % mod;
}
int guess_nth_term(vector<int> x, ll n) {
    if (n < x.size()) return x[n];
    vector<int> v = berlekamp_massey(x);
    if (v.empty()) return 0;
    return get_nth(v, x, n);
}
struct elem {
    int x, y, v;
};  // A_(x, y) <- v, 0-based. no duplicate please..
vector<int> get_min_poly(int n, vector<elem> M) {
    // smallest poly P such that A^i = sum_{j < i} {A^j \times P_j}
    vector<int> rnd1, rnd2;
    mt19937 rng(0x14004);
    auto randint = [&rng](int lb, int ub) {
        return uniform_int_distribution<int>(lb, ub)(rng);
    };
    for (int i = 0; i < n; i++) {
        rnd1.push_back(randint(1, mod - 1));
        rnd2.push_back(randint(1, mod - 1));
    }
    vector<int> gobs;
    for (int i = 0; i < 2 * n + 2; i++) {
        int tmp = 0;
        for (int j = 0; j < n; j++) {
            tmp += 1ll * rnd2[j] * rnd1[j] % mod;
            if (tmp >= mod) tmp -= mod;
        }
        gobs.push_back(tmp);
        vector<int> nxt(n);
        for (auto &i : M) {
            nxt[i.x] += 1ll * i.v * rnd1[i.y] % mod;
            if (nxt[i.x] >= mod) nxt[i.x] -= mod;
        }
        rnd1 = nxt;
    }
    auto sol = berlekamp_massey(gobs);
    reverse(sol.begin(), sol.end());
    return sol;
}
ll det(int n, vector<elem> M) {
    vector<int> rnd;
    mt19937 rng(0x14004);
    auto randint = [&rng](int lb, int ub) {
        return uniform_int_distribution<int>(lb, ub)(rng);
    };
    for (int i = 0; i < n; i++) rnd.push_back(randint(1, mod - 1));
    for (auto &i : M) {
        i.v = 1ll * i.v * rnd[i.y] % mod;
    }
    auto sol = get_min_poly(n, M)[0];
    if (n % 2 == 0) sol = mod - sol;
    for (auto &i : rnd) sol = 1ll * sol * ipow(i, mod - 2) % mod;
    return sol;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v = {
        1,         272,       589185,    930336768, 853401154, 217676188,
        136558333, 415722813, 985269529, 791527976, 201836136, 382110354,
        441223705, 661537677, 641601343, 897033284, 816519670, 365311407,
        300643484, 936803543, 681929467, 462484986, 13900203,  657627114,
        96637209,  577140657, 600647073, 254604056, 102389682, 811580173,
        592550067, 587171680, 526467503, 265885773, 951722780, 219627841,
        371508152, 283501391, 159234514, 439380999, 722868959, 125599834,
        351398134, 456317548, 365496182, 614778702, 502680047, 193063685,
        309004764, 743901785, 870955115, 312807829, 160375015, 691844624,
        137034372, 350330868, 895680450, 282610535, 317897557, 28600551,
        583305647, 539409363, 327406961, 627805385, 680183978, 681299085,
        954964592, 743524009, 788048339, 699454626, 666369521, 857206425,
        490463127, 477198247, 599963928, 21247982,  107843532, 753662937,
        239039324, 608530376, 523383010, 654448101, 801430395, 393034561,
        93313778,  983052766, 240336620, 825539982, 525118275, 563899476,
        706271688, 547405697, 477082486, 664058071, 353207278, 729486413,
        795704637, 999271072, 540749624, 411451016, 736422999, 879369181,
        918733916, 982303557, 512499644, 261033810, 391766409, 334092786,
        931794834, 854181848, 821090190, 751839258, 433126935, 571194155,
        52438113,  552977155, 320805296, 173355929, 969659468, 258854248,
        159509877, 374487748, 401382023, 44060530,  510164669, 336596764,
        652050424, 373872552, 517226592, 719871041, 43959496,  235333335,
        304962191, 253114421, 43638769,  361871585, 8060121,   147014624,
        114846460, 430864038, 368951246, 863795701, 36066788,  971606149,
        935875286, 486724123, 73790652,  236936530, 307697424, 753314001,
        40450345,  529462842, 166162047, 974102330, 600865526, 63237062,
        749041914, 670937123, 806399597, 776678839, 842565920, 608499253,
        469062485, 842196981, 247762946, 778570576, 237951782, 286343384,
        988318575, 147255879, 905747089, 711062313, 21396079,  826846622,
        443781794, 786474911, 400737121, 844768961, 686214818, 590050845,
        855473150, 18501778,  33258755,  398169058, 811192244, 710397887,
        591757177, 775311969, 168256434, 509615161, 489764304, 605188191,
        498085780, 164388183, 524662873, 322602324, 853641480, 205349527,
        308211944, 93153206};
    ll n;
    cin >> n;
    cout << guess_nth_term(v, n) << '\n';
}