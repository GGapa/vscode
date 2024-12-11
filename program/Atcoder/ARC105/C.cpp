#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
using PII = pair<int, int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];

    vector<PII> B(m + 1);
    rep(i, 1, m) cin >> B[i].first >> B[i].second;
    sort(B.begin() + 1, B.end(), [](const PII &x, const PII &y) {
        return x.second < y.second;
    });

    vector<int> mx(m + 2), sec(m + 1);
    rep(i, 2, m + 1) mx[i] = max(mx[i - 1], B[i - 1].first), sec[i - 1] = B[i - 1].second;

    if(*max_element(A.begin() + 1, A.end()) > B[1].second) return cout << -1 << '\n', 0;

    vector<int> id(n);
    iota(id.begin(), id.end(), 1);
    LL ans = LLONG_MAX;
    do {
        vector<LL> F(n + 1);
        rep(i, 2, n) {
            int sum = A[id[i - 1]];
            per(j, i - 1, 1) {
                sum += A[id[j - 1]];
                int t = lower_bound(sec.begin() + 1, sec.end(), sum) - sec.begin();
                F[i] = max(F[i], F[j] + mx[t]);
            }
        }
        ans = min(ans, F[n]);
    }while(next_permutation(id.begin(), id.end()));
    
    cout << ans << '\n';
    return 0;
}
