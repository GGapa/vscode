#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
#define int long long
using VI = vector<int>;
const int N = 20 + 5;

vector<set<int>> G(N);
unordered_map<int, int> mp, tt, ctt;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, t; cin >> n >> t;    
    rep(i, 1, n) rep(j, 1, n) {
        char c; cin >> c;
        if(c == '1') G[i].insert(j), G[j].insert(i);
    }    
    vector<int> A(n + 1), B(n + 1), em(n + 1);
    int ans = 0;
    for(auto i : G[1]) A[i]++, ans++;
    while(--t) {
        int cnt = 0;
        rep(i, 1, n) {
            cnt += G[i].size() * (1 + !(A[i] % 2));
            for(auto j : G[i]) B[j] += (1 + !(A[i] % 2));
        }
        tt[t] = cnt;
        ans += cnt;
        A = B; B = em;
        if(ctt[cnt] >= 200) {
            int tmp = 0, dis = 1;
            for(; ; dis++) {
                bool tag = true;
                rep(i, 0, dis - 1) if(tt[t + i] != tt[t + dis + i]) {tag = false;break;}
                if(tag) break;
            }
            rep(i, 0, dis - 1) tmp += tt[t + i];
            ll ret = ans;
            ret += 1ll * tmp * ((t - 1) / dis);
            per(i, t + dis - 1, t + dis - 1 - (t - 1) % dis + 1) ret += tt[i];
            cout << ret << '\n';
            return 0;
        }
        mp[cnt] = t;
        ctt[cnt]++;
    }
    cout << ans << '\n';
    return 0;
}