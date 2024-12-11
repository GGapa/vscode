// Twenty Questions
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int INF = 1e9;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int n, m; cin >> m >> n && m ; ) {
        vector<int> A(n + 1);
        rep(i, 1, n) {
            string s; cin >> s;
            bitset<11> bit(s);
            // A.insert(bit.to_ullong());
            A[i] = bit.to_ullong();
        }
        if(n == 1) {
            cout << 0 << '\n';
            continue;
        }
        int S = (1 << m) - 1;
        vector<VI> F(S + 1, VI(S + 1, -1));
        function<int(int, int)> dp = [&](int s, int a) {    //选过了和确定了的
            auto &f = F[s][a];
            if(f != -1) return f;
            f = 1e9;
            int cnt = 0;
            rep(i, 1, n) if((A[i] & s) == a) cnt++;
            if(cnt <= 1) return f = 0; 
            rep(i, 0, m - 1) if(!(s & (1 << i))) {
                f = min(f, max(dp(s | (1 << i), a | (1 << i)), dp(s | (1 << i), a)) + 1);
            }
            return f;
        };
        cout << dp(0, 0) << '\n';
    }
    return 0;
}