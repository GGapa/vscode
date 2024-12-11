#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define CSP2024 GG BUT I WILL WIN NOIP2024
using namespace std;
using LL = long long;
using VI = vector<int>;
using PQX = priority_queue<int>;
using PQM = priority_queue<int, VI, greater<int>>;

const int N = 1e5 + 5;

int a[N], b[N];

struct Node {

    template<typename T>
    void pop(T &a) {
        while(!a[1].empty() && a[0].top() == a[1].top()) a[0].pop(), a[1].pop();
    }

    int xl, xr, ml, mr;
    vector<PQX> mxr, mxl;
    vector<PQM> mnr, mnl;
    Node() : mxr(2), mxl(2), mnr(2), mnl(2) {}
    void update() {
        pop(mxr); pop(mxl); pop(mnr); pop(mnl);
        if(mxr[0].empty()) xl = xr = ml = mr = -1;
        else ml = mnl[0].top(), xl = mxl[0].top(), mr = mnr[0].top(), xr = mxr[0].top();
    }

    // tp = 0 增加，否则删除
    void op(int tp, int l, int r) {  
        mxl[tp].push(l), mnl[tp].push(l);
        mxr[tp].push(r), mnr[tp].push(r);
        update();
    }
};

vector<Node> F;
set<array<int, 3>> s;

void insert(int x) {
    auto it = s.lower_bound({b[x] + 1, 0, 0});
    int id = -1;
    if(it != s.end() && a[x] > (*it)[0]) id = (*it)[2], s.erase(it);    
    else if(it != s.begin()) {
        auto nw = prev(it);
        if(b[x] < (*nw)[1]) id = (*nw)[2], s.erase(nw);
    }

    if(id == -1) id = F.size(), F.emplace_back(Node());
    F[id].op(0, b[x], a[x]);
    s.insert({F[id].ml, F[id].xr, id});
}

void del(int x) {
    auto it = s.lower_bound({b[x] + 1, 0, 0}); it--;
    int id = (*it)[2]; 
    s.erase(it);
    F[id].op(1, b[x], a[x]);
    if(F[id].ml != -1) s.insert({F[id].ml, F[id].xr, id});
}

bool check(int x, int y) {return min(a[x], F[y].mr) > max(b[x], F[y].xl); }
 
bool check(int x) {
    auto it = s.lower_bound({b[x] + 1, 0, 0});
    if(it != s.end())  {
        auto nw = next(it); 
        if(a[x] > (*it)[0] && !check(x, (*it)[2])) return false;        // 情况 1 不和小区间相交但是不相离
        if(nw != s.end() && a[x] > (*nw)[0])  return false;             // 情况 2 链接了两坨不相同的区间
    }
    if(it != s.begin()) {
        auto nw = prev(it);
        if(b[x] < (*nw)[1] && !check(x, (*nw)[2])) return false;                // 情况 1 不和小区间相交但是不相离
        if(it != s.end() && (*nw)[1] > b[x] && a[x] > (*it)[0]) return false;   // 情况 2 链接了两坨不相同的区间，这里考虑的是横跨的情况
    }
    return true;
}

void solve() {
    int n; cin >> n;
    rep(i, 1, n) cin >> a[i] >> b[i];
    F.clear(); s.clear();
    LL ans = 0;
    for(int i = 1, j = 1; i <= n; i++) {
        while(j <= n && check(j)) insert(j++);        
        ans += (j - i);
        // cerr << i << " " << j << endl;
        // cerr << i << " " << s.size() << '\n';
        
        del(i);
    }
    cout << ans << '\n';
}

signed main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
/*
我们称一坨区间代表若干个交不为空的区间构成的集合。
我们定义一坨区间的小区间为这些区间的交
定义一坨区间的大区间为这些区间的并
*/