// P7113 

#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
typedef __int128 BI;
using VI = vector<int>;

BI gcd(BI a, BI b) {return (b == 0 ? a : gcd(b, a % b));}

struct Frac {
    BI x, y;
    Frac(BI _x = 0, BI _y = 1) : x(_x), y(_y) {
        BI g = gcd(x, y);
        x /= g, y /= g;
    }
    Frac operator/(const BI &a) const {return Frac(x, y * a);}
    Frac operator+(const Frac &a) const {return Frac(x * a.y + a.x * y, y * a.y);}
};

vector<VI> G;
vector<int> D;
vector<Frac> F;

ostream &operator<<(ostream &os, const BI &n) {
    if (n > 9) os << (n / 10);
    return os << (int)(n % 10);
}

void dfs(int x, Frac v) {
    F[x] = F[x] + v;
    if(D[x]) v = v / D[x];
    for(auto to : G[x]) dfs(to, v);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    G.resize(n + 1); F.resize(n + 1); D.resize(n +1);
    vector<int> O;
    rep(i, 1, n) {
        cin >> D[i];
        G[i].resize(D[i]);
        for(auto &j : G[i]) cin >> j;
        if(D[i] == 0) O.push_back(i);
    }
    Frac tmp{1, 1};
    rep(i, 1, m) dfs(i, tmp);
    for(auto i : O) cout << F[i].x << " " << F[i].y << '\n';
    return 0;
}