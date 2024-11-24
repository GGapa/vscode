#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
#define int long long
using VI = vector<int>;

typedef long long LL;
using VI = vector<int>;
const LL p = 1e10;
 
struct LINT {
    vector<LL> A; 
    int n;
    LINT() : A(1) {}
    LINT(LL x) : A(1) {
        for(; x; x /= p) A.push_back(x % p);
        n = (int)A.size() - 1; 
    }
    LINT(string x) : A(1){
        reverse(x.begin(), x.end());
        int le = to_string(p).size();
        LL ct = 0;
        for(int i = 0, tt = 0, pw = 1; i < x.size(); i++) {
            tt++;
            ct += pw * (x[i] - '0');
            pw *= 10;
            if(tt == le - 1) {
                A.push_back(ct);
                tt = 0;
                ct = 0;
                pw = 1;
            }
        }
        A.push_back(ct);
        n = (int)A.size() - 1; 
    }
    LINT operator+(LINT B) {
        LINT tmp; tmp.n = max(B.n, n);
        tmp.A.resize(tmp.n + 1);
        rep(i, 1, tmp.n) {
            if(i <= n) tmp.A[i] += A[i];
            if(i <= B.n) tmp.A[i] += B.A[i];
            if(tmp.A[i] >= p && i + 1 > tmp.n) tmp.A.push_back(tmp.A[i] / p);
            else tmp.A[i + 1] += tmp.A[i] / p;
            tmp.A[i] %= p;
        }
        return tmp;
    } 
    LINT operator*(int x) {
        LINT tmp; tmp.n = n; tmp.A = A;
        rep(i, 1, tmp.n) tmp.A[i] *= x;
        rep(i, 1, tmp.n - 1) tmp.A[i + 1] += tmp.A[i] / p, tmp.A[i] %= p;
        for(; tmp.A[tmp.n] >= p; ) tmp.A.push_back(tmp.A[tmp.n] / p), tmp.A[tmp.n] %= p, tmp.n++;
        return tmp;
    }
    string to_str() {
        string ans = to_string(A[n]);
        per(i, n - 1, 1) {
            int c = 10;
            while(c < p && A[i] * c < p) ans += "0", c *= 10;
            ans += to_string(A[i]);
        }
        return ans;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string a, b; cin >> a >> b;
    auto A = LINT(a);
    reverse(b.begin(), b.end());
    int m = b.size();
    LINT ans(0);
    int c; cin >> c;
    rep(i, 0, m - 1) {
        LINT tmp = A * (b[i] - '0');
        string s = tmp.to_str();
        rep(j, 1, i) s += "0";
        ans = ans + LINT(s);
    }
    string s = ans.to_str();
    int cnt = 0;
    for(auto ch : s) if(ch == '0' + c) cnt++;
    cout << cnt << '\n';
    return 0;
}