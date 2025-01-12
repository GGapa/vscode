#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int INF = 1e6;

int F[302][302][(1 << 7) + 5];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    vector<int> A(n + 2);
    int ans = 0;
    rep(i, 1, n) cin >> A[i], ans += A[i] * 2;
    A[0] = A[n + 1] = INF; ans += 2 * INF;

    vector<int> lock(n + 1), B(k + 2);
    rep(i, 2, k + 1) cin >> B[i], lock[B[i]] = 1;
    B[1] = 0, B.emplace_back(n + 1);
    
    vector<int> itv, L, R;
    rep(i, 1, k + 1) {
        if(B[i + 1] == B[i] + 1) {
            ans += abs(A[B[i + 1]] - A[B[i]]) ;
            continue;
        }
        itv.emplace_back(B[i + 1] - B[i] - 1);
        L.emplace_back(A[B[i]]);
        R.emplace_back(A[B[i + 1]]);
        if(L.back() > R.back()) swap(L.back(), R.back());
    }

    vector<int> num;
    num.emplace_back(0);
    rep(i, 1, n) if(!lock[i]) num.emplace_back(A[i]);

    sort(num.begin(), num.end());
    int m = (int)num.size() - 1, tp = (1 << (int)itv.size()) - 1;

    vector<int> sum(tp + 1);
    rep(s, 0, tp) rep(i, 0, (int)itv.size() - 1) if(s >> i & 1) sum[s] += itv[i];
    rep(l, 0, m + 1) rep(r, 0, m + 1) rep(s, 0, tp) F[l][r][s] = (s == 0 ? 0 : 1e9);

    rep(i, 1, m) for(int l = 1, r; (r = l + i - 1) <= m; l++) {
        rep(s, 0, tp) {
            F[l][r][s] = min(F[l + 1][r][s], F[l][r - 1][s]);
            if(sum[s] > i) continue;
            if(sum[s] == i) {
                rep(x, 0, (int)itv.size() - 1) if(s >> x & 1) {
                    if(itv[x] == 1 && i == 1) F[l][r][s] = min(F[l][r][s], abs(L[x] - num[l]) + abs(R[x] - num[r]));
                    else if(itv[x] > 1) F[l][r][s] = min(F[l][r][s], F[l + 1][r - 1][s ^ (1 << x)] + abs(L[x] - num[l]) + abs(R[x] - num[r]) + num[r] - num[l]);
                }
            }
            for(int t = (s - 1) & s; t; t = (t - 1) & s)
                F[l][r][s] = min(F[l][r][s], F[l][l + sum[t] - 1][t] + F[l + sum[t]][r][s ^ t]);
            // cerr << l << " " << r << " " << s << " " << F[l][r][s] << '\n';
        } 
    }

    ans += F[1][m][tp];
    ans /= 2;  ans -= 2 * INF;
    cout << ans << '\n';    
    return 0;
}