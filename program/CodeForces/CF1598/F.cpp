//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 21;

unordered_map<int, int> cnt[N], lt[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int tp = (1 << n) - 1;
    vector<int> num(n + 1), mn(n + 1);
    vector<int> sum(tp + 1);
    rep(i, 0, n - 1) {
        string s; cin >> s;
        int len = s.size();
        rep(j, 0, len - 1) {
            num[i] += 1 - 2 * (s[j] == ')');
            mn[i] = min(mn[i], num[i]);
            if(++cnt[i][num[i]] == 1) lt[i][num[i]] = cnt[i][num[i] + 1];
        }
    } 
    rep(s, 0, tp) rep(i, 0, n - 1) if((s >> i) & 1) sum[s] += num[i];
    int ans = 0;
    vector<int> F(tp + 1), tag(tp + 1);
    tag[0] = 1; 
    rep(s, 0, tp) {
        if(!tag[s]) sum[s] = -1;
        if(sum[s] < 0) {
            F[s] = 0;
            continue;
        }
        rep(i, 0, n - 1) if(!((s >> i) & 1)) {
            int &f = F[s], &f1 = F[s ^ (1 << i)];
            if(sum[s] + mn[i] >= 0) f1 = max(f1, f + cnt[i][-sum[s]]), tag[s ^ (1 << i)] = 1;
            else ans = max(ans, f + lt[i][-sum[s] - 1]) ;
        }
        ans = max(ans, F[s]);
    }
    cout << ans << '\n';
    return 0;
}