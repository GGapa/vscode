#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

template <typename T>
struct BIT {
    int n;
    vector<T> tr;
    void init(int nn) {
        n = nn + 1;
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

constexpr int N = 2e6 + 5;

int n, m; 
int A[N], B[N], C[N], id[N], rt[N];
char op[N];
vector<int> G[N];

int in[N], out[N];
void dfs(int x) {
    in[x] = ++in[N - 1]; 
    for(auto to : G[x]) dfs(to);
    out[x] = in[N - 1];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int q; cin >> q;
    id[rt[2] = 1] = 1;
    n = m = id[rt[1] = 2] = 2;
    rep(i, 1, q) {
        cin >> op[i] >> A[i];
        int &x = id[A[i]];
        if(op[i] == 'W') {
            G[x].emplace_back(B[i] = ++m);
            rt[m] = rt[x];
            id[++n] = ++m;
            x = rt[m] = m - 1;            
        }
        else if(op[i] == 'Z') {
            G[x].emplace_back(id[++n] = C[i] = ++m);
            B[i] = rt[m] = rt[x];
        }
        else B[i] = x;
    }
    rep(i, 1, m) if(!in[i]) dfs(i);

    BIT<int> t1(N + 1), t2(N + 1);
    rep(i, 1, q) {
        if(op[i] != '?' && B[i] > 2) t1.add(in[B[i]], 1), t1.add(out[B[i]] + 1, -1);
        if(op[i] == 'Z') t2.add(in[C[i]], 1);
        if(op[i] == '?') cout << t1.ask(in[B[i]]) + t2.ask(out[rt[B[i]]]) - t2.ask(in[rt[B[i]]]) + 1 << '\n';
    }
    return 0;
}
