#include <bits/stdc++.h>
#include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;

constexpr int mod = 1e9 + 7;

namespace LS {
    constexpr int N = 1e6 + 5;
    int pri[N], phi[N], mn[N], mu[N];
    bitset<N> vis;

    void init(){
        mu[1] = 1;
        rep(i, 2, N - 1) {
            if(!vis[i]) pri[++pri[0]] = i, mn[i] = i, phi[i] = i - 1, mu[i] = -1;
            for(int j = 1; j <= pri[0] && i * pri[j] < N; j++) {
                int tt = i * pri[j];
                vis[tt] = 1;
                mn[tt] = pri[j];
                if(i % pri[j] == 0) {
                    phi[tt]  = phi[i] * pri[j];
                    break;
                }
                else phi[tt] = phi[i] * phi[pri[j]];
                mu[tt] = -mu[i];
            }
        }
    }

    vector<pair<int, int>> getpri(int x) {
        vector<pair<int, int>> ret;
        while(x > 1) {
            int t = mn[x], cnt = 0;
            while(x % t == 0) x /= t, cnt++;
            ret.emplace_back(t, cnt);
        }
        return ret;
    } 
}using LS::getpri;

namespace pre {
    constexpr LL qpow(LL x, LL y){   // 因为使用了 template 所以进 qpow 的时候别忘记开 long long
        LL ret = 1;
        for(; y; y >>= 1) {
            if(y & 1) (ret = ret * x % mod);
            (x = x * x % mod) ;
        }
        return ret;
    }

    constexpr LL inv(LL x) {return qpow(x, mod - 2); }
}   
using namespace pre;


constexpr int N = 5e5 + 5;

unordered_map<int, int> mul[N], iv[N];
vector<pair<int, int>> mnn[N];


void solve() {
    int n; cin >> n;
    vector<int> A(n + 1), vis(n + 1);
    rep(i, 1, n) cin >> A[i];
    
    vector<int> cyc; // 置换环
    gp_hash_table<int, int> ctt;    // 环大小计数
    rep(i, 1, n) if(!vis[i]) {
        cyc.emplace_back(0);
        for(int x = i; !vis[x]; x = A[x]) vis[x] = 1, cyc.back()++;
        ctt[cyc.back()]++;
    }

    gp_hash_table<int, multiset<int>> mx;
    LL ans = 1;
    rep(i, 1, n) mx[i].insert(0);

    auto add = [&](int x) {
        for(auto p : mnn[x]) {
            int t = *mx[p.first].rbegin();
            mx[p.first].insert(p.second);
            if(p.second > t) (ans *= qpow(p.first, p.second - t)) %= mod;
            // mx[p.first].erase(mx[p.first].begin());
        }
    };

    auto del = [&](int x) {
        for(auto p : mnn[x]) {
            int t = *mx[p.first].rbegin();
            mx[p.first].erase(mx[p.first].find(p.second));
            if(*mx[p.first].rbegin() < t) (ans *= qpow(p.first, mod - 1 + *mx[p.first].rbegin() - t)) %= mod;
        }
    };

    for(auto a : cyc) add(a);

    sort(cyc.begin(), cyc.end());
    cyc.erase(unique(cyc.begin(), cyc.end()), cyc.end());

    LL sum = 0;
    rep(i, 0, (int)cyc.size() - 1) {
        del(cyc[i]);
        rep(j, i + 1, (int)cyc.size() - 1) {
            del(cyc[j]);
            add(cyc[i] + cyc[j]);
             (sum += 2ll * ans * cyc[i] % mod * cyc[j] % mod * ctt[cyc[i]] % mod * (ctt[cyc[j]]) % mod) %= mod;
            add(cyc[j]);
            del(cyc[i] + cyc[j]);
        }
        if(ctt[cyc[i]] > 1) {
            del(cyc[i]);
            add(cyc[i] + cyc[i]);
            (sum += ans * cyc[i] % mod * cyc[i] % mod * (ctt[cyc[i]] - 1) % mod *ctt[cyc[i]] % mod) %= mod;
            add(cyc[i]);
            del(cyc[i] + cyc[i]);
        }
        add(cyc[i]);
    }

    cout << sum << '\n';
}

signed main() {
    // freopen("P8338.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    LS::init();
    rep(i, 2, N - 1) mnn[i] = getpri(i);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}