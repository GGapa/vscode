#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

template <typename T>
struct BIT {
    int n;
    vector<T> tr;
    void init(int nn) {
        n = nn;
        tr.assign(n + 5, T{});
    }
    BIT (int nn = 0) {
        init(nn);
    }
    void add(int x, const T &v) {
        for(++x; x <= n; x += x & -x) tr[x] = (tr[x] + v);
    }
    T ask(int x) {
        T ret{};
        for(++x; x >= 1; x -= x & -x) ret = (ret + tr[x]);
        return ret;
    }
    T query(int l, int r) {
        return ask(r) - ask(l);
    }
};

int n, m;  

string exc = "AUGC";

constexpr int N = 2e6 + 5;

struct Trie {
    int tr[N][4], in[N], out[N], dfn[N], ctt[N];
    int idx = 0, cnt = 0;
    void insert(const string &s) {
        int it = 0;
        for(auto cc : s) {
            int c = exc.find(cc);
            if(!tr[it][c]) tr[it][c] = ++idx;
            it = tr[it][c];
        }
        ctt[it]++;
    }
    pair<int, int> query(const string &s) {
        int it = 0;
        for(auto cc : s) {
            int c = exc.find(cc);
            if(!tr[it][c]) return {-1, -1};
            it = tr[it][c];
        }
        return {in[it] + 1, out[it]};
    }
    void dfs(int x) {
        in[x] = cnt;
        cnt += ctt[x];
        rep(i, 0, 3) if(tr[x][i]) dfs(tr[x][i]);
        out[x] = cnt;
    }
}pre, suf;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vector<string> S(n + 1);
    rep(i, 1, n) {
        string s; cin >> s;
        pre.insert(s);
        suf.insert(string(s.rbegin(), s.rend()));
        S[i] = s; 
    }

    pre.dfs(0);
    suf.dfs(0);

    vector<VI> nd(n + 1);
    vector<vector<array<int, 3>>> itv(n + 1);
    BIT<int> tr(n + 1);
    vector<int> ans(m + 1);

    rep(i, 1, n) {
        string s = S[i];
        int x, y;
        x = pre.query(s).first;
        y = suf.query(string(s.rbegin(), s.rend())).first;
        nd[x].emplace_back(y);
    }

    rep(i, 1, m) {
        string s, t; cin >> s >> t;
        int x1, y1, x2, y2;

        auto tmp = pre.query(s);
        x1 = tmp.first, x2 = tmp.second;
        if(x1 == -1) continue;

        tmp = suf.query(string(t.rbegin(), t.rend()));
        y1 = tmp.first, y2 = tmp.second;
        if(y1 == -1) continue;

        itv[x2].push_back({y2, i, 1});
        itv[x2].push_back({y1 - 1, i, -1});
        itv[x1 - 1].push_back({y2, i, -1});
        itv[x1 - 1].push_back({y1 - 1, i, 1});
    }

    rep(i, 0, n) {
        for(auto a : nd[i]) tr.add(a, 1);
        for(auto p : itv[i]) 
            ans[p[1]] += p[2] * tr.ask(p[0]);
    }

    rep(i, 1, m) cout << ans[i] << '\n';
    return 0;
}