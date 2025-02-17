#include <bits/stdc++.h>
// #include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
// using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

constexpr int N = 1e5 + 5;

int n, q, m;
int h[N], t[N];
vector<AI<2>> G[N];

LL work(int st, int ed) {
    using AI = array<LL, 2>;
    constexpr LL INF = 1e18;
    vector<LL> dis(n + 1, INF);
    priority_queue<AI, vector<AI>, greater<AI>> q;
    dis[st] = 0; q.push({0, st});
    while(!q.empty()) {
        int x = q.top()[1], w = q.top()[0]; q.pop();
        if(dis[x] < w) continue;
        for(auto i : G[x]) {
            auto [to, w] = i;
            if(dis[to] > dis[x] + w) {
                dis[to] = dis[x] + w;
                q.push({dis[to], to});
            }
        }   
    }
    return dis[ed];
}
signed main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> q >> m;
    rep(i, 1, n) cin >> h[i];
    rep(i, 1, n) cin >> t[i];

    rep(i, 1, n) rep(j, 1, n) G[i].push_back({j, 1 + (h[i] > h[j] + m ? t[j] : 0)});

    for(int x, y; q--; ) {
        cin >> x >> y;
        cout << work(x, y) << '\n';
    }

    return 0;
}
/*
4 1 2
1 4 7 8
0 7 2 1
4 3
*/