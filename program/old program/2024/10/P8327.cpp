// 1h 左右
// 15:13
#include <bits/stdc++.h>
//#include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define CSP2024 GG BUT I WILL WIN NOIP2024
using namespace std;
//using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
const int N = 1e6 + 5;

int mn[N];

#define nc() getchar()
int read()
{
    int x=0,f=1;
    char ch=nc();
    while(ch<48||ch>57)
    {
        if(ch=='-')
            f=-1;
        ch=nc();
    }
    while(ch>=48&&ch<=57)
        x=x*10+ch-48,ch=nc();
   	return x*f;
}

void init() {
    vector<int> p;
    for (int i = 2; i < N; i++) {
        if (mn[i] == 0) {
            mn[i] = i;
            p.push_back(i);
        }
        
        for (auto pp : p) {
            if (i * pp >= N) {
                break;
            }
            mn[i * pp] = pp;
            if (pp == mn[i]) {
                break;
            }
        }
    }
}

vector<int> pi[N];

vector<int> get(int x) {
    if(!pi[x].empty()) return pi[x];
    vector<int> ret;
    while(x > 1) {
        ret.emplace_back(mn[x]);
        int t = mn[x];
        while(x % t == 0) x /= t;
    }
    return pi[x] = ret;
}
 


#define ls (x << 1)
#define rs (x << 1 | 1)
namespace SGT {
    const int INF = 1e9;
    struct Node {
        int mn, tg;
    };
    Node tr[N << 2];
    int n;
    void build(int x = 1, int l = 1, int r = n) {
        // if(r == -1) r = n;
        tr[x].mn = tr[x].tg = INF;
        if(l == r) return ;
        int mid = l + r >> 1;
        build(ls, l, mid); build(rs, mid + 1, r);
    }
    void init(int nn) {n = nn; build(); }
    void apply(int x, int v) { 
        tr[x].mn = min(tr[x].mn, v);
        tr[x].tg = min(tr[x].tg, v);
    }
    void pushup(int x) { tr[x].mn = min(tr[ls].mn, tr[rs].mn); }
    void pushdown(int x) {
        if(tr[x].tg == INF) return;
        apply(ls, tr[x].tg); apply(rs, tr[x].tg);
        tr[x].tg = INF;
    }
    void modify(int L, int R, int v, int x = 1, int l = 1, int r = n) {
        // if(r == -1) r = n;
        if(L <= l && r <= R) return apply(x, v);
        int mid = (l + r) >> 1;
        pushdown(x);
        if(L <= mid) modify(L, R, v, ls, l, mid);
        if(mid < R) modify(L, R, v, rs, mid + 1, r);
        pushup(x);
    }
    int query(int it, int x = 1, int l = 1, int r = n) {
        // if(r == -1) r = n;
        if(l == r) return tr[x].mn;
        int mid = (l + r) >> 1;
        pushdown(x);
        int ret = INF;
        if(it <= mid) ret = min(ret, query(it, ls, l, mid));
        if(mid < it) ret = min(ret, query(it, rs, mid + 1 ,r));
        // pushup(x);
        return ret;
    }
}
#undef rs
#undef ls

int n, q;
set<int> S[N];
multiset<array<int, 2>> vec[N];
int have[N], in[N];

signed main() {
    freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int ST = clock();
    init();
    
    // cin >> n >> q;
    n = read(); q = read();
    // rep(i, 1, n) pi[i] = get(i);

    using AI = array<int, 4>;
    vector<AI> ad, que;
    int tot = 0;

    rep(i, 1, q) {
        char op = getchar();
        while(!isalpha(op)) op = getchar();
        if(op == 'S') {
            int x = read(); 
            tot++;
            if(have[x]) {
                for(auto a : get(x)) {
                    auto &s = S[a]; 
                    for(auto p : vec[x]) {
                        vec[p[0]].erase(vec[p[0]].find({x, p[1]}));
                        ad.push_back({min(x, p[0]), max(x, p[0]), p[1], tot});
                    }
                    S[a].erase(x);
                    vec[x].clear();
                    auto it = s.upper_bound(x);
                    auto it1 = s.lower_bound(x);
                    if(it != s.end() && it1 != s.begin()) {
                        it1--;
                        vec[*it].insert({*it1, tot});
                        vec[*it1].insert({*it, tot});
                    }
                }
            }
            else {
                for(auto a : get(x)) {
                    auto &s = S[a]; 
                    auto it = s.upper_bound(x);
                    bool tag = true; in[x] = tot;
                    if(it != s.end()) vec[x].insert({*it, tot}), vec[*it].insert({x, tot});
                    else tag = false;   

                    auto it1 = s.lower_bound(x);
                    if(it != s.begin()) {
                        it1--;
                        vec[x].insert({*it1, tot});
                        vec[*it1].insert({x, tot});
                    }
                    else tag = false;

                    s.insert(x); 
                 }
            }   
            have[x] ^= 1;
        }   
        else {
            int l = read(), r = read(); 
            que.push_back({l, r, (int)que.size(), tot});
        }
    }  
    
    rep(x, 1, n) if(have[x]) {
        for(auto a : get(x)) {
            auto &s = S[a]; 
            for(auto p : vec[x]) {
                vec[p[0]].erase(vec[p[0]].find({x, p[1]}));
                ad.push_back({min(x, p[0]), max(x, p[0]), p[1], tot});
            }
            S[a].erase(x);
            vec[x].clear();
            auto it = s.upper_bound(x);
            auto it1 = s.lower_bound(x);
            if(it != s.end() && it1 != s.begin()) {
                it1--;
                vec[*it].insert({*it1, q});
                vec[*it1].insert({*it, q});
            }
        }
    }
    
    cerr << (clock() - ST) * 1.0 / CLOCKS_PER_SEC << '\n';
    SGT::init(tot);

    sort(ad.begin(), ad.end());
    sort(que.begin(), que.end());
    vector<int> ans(que.size());
    ad.erase(unique(ad.begin(), ad.end()), ad.end());
    
	// cerr << ad.size() << '\n';
    // for(auto a : ad) cerr << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << '\n';

    for(int i = n, i1 = (int)ad.size() - 1, i2 = (int)que.size() - 1; i; i--) {
        while(i1 >= 0 && ad[i1][0] >= i) {
            SGT::modify(ad[i1][2], ad[i1][3], ad[i1][1]);
            i1--;
        }
        while(i2 >= 0 && que[i2][0] >= i) {
            ans[que[i2][2]] = (SGT::query(que[i2][3]) <= que[i2][1]);
            i2--;
        }
    }
    // cerr << (clock() - ST) * 1.0 / CLOCKS_PER_SEC << '\n';

    for(auto a : ans) cout << (a ? "DA" : "NE") << '\n';
    return 0;
}
/*
今天心情不好，敲会数据结构题发泄一下。
先考虑 对于每一个质因子预处理一个区间，前缀取 min，但是这样子做是 n log^2 n 的，太慢了，
由于我们是对前缀取 min，所以我们可以把操作放在时间轴上进行考虑。
*/
