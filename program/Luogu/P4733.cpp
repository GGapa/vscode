#include <bits/stdc++.h>
#include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

constexpr int N = 12e4 + 5;

vector<AI<2>> G[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    int m = n << 1;
    vector<int> deg(m * 2 + 1);

    auto add = [&](int u, int v, int w) {
        deg[u]++; deg[v]++;
        G[u].push_back({v, w}); G[v].push_back({u, w});
    };
    for(int i = 1, l, r, s; i <= m; i++) {
        cin >> l >> r >> s;
        add(i, l + m, s);
        add(i, r + m + n, -s);
    }

    LL sum = 0; 
    queue<int> q;
    rep(i, m + 1, 2 * m) {
        if(deg[i] == 0) return cout << "NO", 0;
        else if(deg[i] == 1) q.emplace(i);
    }
    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(auto i : G[x]) {
            if(deg[i[0]] > 1) {
                if(--deg[i[0]] == 1) q.push(i[0]);
                if(i[0] > m) sum += i[1];
            }
        }
    }

    cc_hash_table<int, int> mp;
    vector<int> s(m * 2 + 1), t = s;
    int cnt = 0;
    rep(i, 1, 2 * m) if(deg[i] > 1) {
        int ss[] = {0, 0};
        for(int x = i, j = 0; deg[x] > 1; ) {
            deg[x] = 1;
            for(auto i : G[x]) if(deg[i[0]] > 1) 
                x = i[0], ss[(j ^= 1)] += i[1];
        }
        if(ss[0] > ss[1]) swap(ss[0], ss[1]);
        int val = ss[1] - ss[0];
        sum += ss[0];
        if(mp.find(val) == mp.end()) 
            mp[val] = ++cnt, s[cnt] = val;
        t[mp[val]]++;
    }
    
    bitset<N * 6> F;
    F[0] = 1;
    rep(i, 1, cnt) {
        for(int j = 1; j < t[i]; j *= 2) 
            F |= F << (j * s[i]), t[i] -= j;
        F |= F << (t[i] * s[i]);
    }
    rep(i, -k, k) if(sum <= i && F[i - sum]) 
        return cout << "YES", 0;
    cout << "NO";

    return 0;
}