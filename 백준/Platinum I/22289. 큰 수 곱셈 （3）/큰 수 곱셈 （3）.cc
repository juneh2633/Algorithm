#include<bits/stdc++.h>

using namespace std;
using cdbl = complex<double>;
const double PI = acos(-1);

void fft(vector<cdbl> &a, bool inv) {
    int n = a.size();
    // bit reversal
    for(int i=1,j=0;i<n;++i) {
        int bit = n>>1;
        while(!((j^=bit) & bit)) bit >>=1;
        if(i<j) swap(a[i],a[j]);
    }
    for(int i=1;i<n;i<<=1) {
        double x = inv? M_PI / i : -M_PI / i;
        cdbl w = cdbl(cos(x),sin(x));
        for(int j=0;j<n;j += i<<1) {
            cdbl p = cdbl(1,0);
            for(int k=0;k<i;++k) {
                cdbl tmp = a[i+j+k] * p;
                a[i+j+k] = a[j+k] - tmp;
                a[j+k] += tmp;
                p *= w;
            }
        }
    }
    if(inv) {
        for(int i=0;i<n;++i) a[i] /= n;
    }
}

vector<cdbl> solve(vector<cdbl> &a, vector<cdbl> &b) {
    int n = 1;
    while(n < a.size() || n < b.size()) n <<= 1;
    n <<= 1;
    a.resize(n); b.resize(n);
    vector<cdbl> c(n);
    fft(a,false); fft(b,false);
    for(int i=0;i<n;++i) c[i] = a[i]*b[i];
    fft(c,true);
    for(int i=0;i<n;++i) {
        c[i] = cdbl(round(c[i].real()),round(c[i].imag()));
    }
    return c;
}

vector<cdbl> parse(string &s, int n) {
    int len = s.size() / n;
    int tmp = 0;
    int i = 0, j = 0;;
    if(s.size() % n) ++len;
    vector<cdbl> ret(len);
    if(s.size() % n) {
        for(;i<s.size()%n;++i) tmp = tmp*10 + s[i] - '0';
        ret[j++] = cdbl(tmp,0);
    }
    while(i < s.size()) {
        tmp = 0;
        for(int k=0;k<n;++k) tmp = tmp*10 + s[i+k] - '0';
        i += n;
        ret[j++] = cdbl(tmp,0);
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    cin.tie(nullptr);
    string s;
    cin >> s;
    if(s == "0") {
        cout << 0 << '\n';
        return 0;
    }
    vector<cdbl> a = parse(s,1);
    cin >> s;
    if(s == "0") {
        cout << 0 << '\n';
        return 0;
    }
    vector<cdbl> b = parse(s,1);
    vector<cdbl> c = solve(a,b);
    int t = 10;
    for(int i=0;i<c.size();++i) {
        if(c[i].real() >= t) {
            if(i == c.size()-1) c.push_back(cdbl((int)c[i].real()/t,0));
            else c[i+1] += cdbl((int)c[i].real()/t,0);
            c[i] = cdbl(((int)c[i].real()) % t,0);
        }
    }
    reverse(c.begin(),c.end());
    int i = 0;
    while(c[i].real() == 0) ++i;
    //cout << (int)c[i++].real();
    for(;i<c.size();++i) cout << (int)c[i].real();
    cout << '\n';
    return 0;
}
