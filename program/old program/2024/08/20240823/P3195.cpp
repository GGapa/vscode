#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, L; cin >> n >> L;   
    vector<LL> S(n + 1), a(n + 1), b(n + 1), F(n + 1);
    rep(i, 1, n) {
        cin >> S[i], S[i] += S[i - 1];
        a[i] = i + S[i] - 1 - L, b[i] = S[i] + i;
    }
    auto X = [&](int i) {return b[i]; } ;
    auto Y = [&](int i) {return b[i] * b[i] + F[i]; }; 
    auto slope = [&](int i, int j) { return 1.0 * (Y(i) - Y(j)) / 1.0 * (X(i) - X(j)); };
    auto calc = [&](int x, int y) { return F[x] + b[x] * b[x] - a[y] * b[x] * 2; };
    auto check = [&](int p1, int p2, int p3) {
        return (X(p2) - X(p3)) * (Y(p1) - Y(p3)) - (X(p1) - X(p3))
            * (Y(p2) - Y(p3)) >= 0; 
    };
    vector<int> q(n * 2) ;
    int t, h; t = h = 1;
    q[h] = 0;
    rep(i, 1, n) {
        while(t < h && calc(q[t], i) >= calc(q[t + 1], i)) t++;
        int j = q[t];
        F[i] = F[j] + (a[i] - b[j]) * (a[i] - b[j]) ;
        while(t < h && check(q[h - 1], q[h], i)) h--;
        q[++h] = i;
    }
    cout << F[n] << '\n';
    return 0;
}