#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const double eps = 1e-7;
const int N = 50000 + 5;

int n, p; 

struct Node {
    int x, y, v;
};
vector<Node> A;

int F[N][62];
int fa[N];

int find(int x) {return (x == fa[x] ? x : fa[x] = find(fa[x]));}
double dis(int i, int j) {return sqrt(1ll * (A[i].x - A[j].x) * (A[i].x - A[j].x) + 1ll * (A[i].y - A[j].y) * (A[i].y - A[j].y));}

bool check(double ds) {
    rep(i, 1, n) {
        rep(j, 0, p) F[i][j] = 0;
        fa[i] = i; F[i][A[i].v] = 1;
    }
    rep(i, 1, n) rep(j, i + 1, n) {
        if(A[j].x - A[i].x > ds) break;
        int x = find(i), y = find(j);
        if(dis(i, j) > ds || x == y) continue;
        vector<int> G(62, 0);
        rep(l, 0, p) if(F[x][l]) rep(r, 0, p) if(F[y][r]) G[l + r] = 1;
        rep(l, 0, p * 2) F[x][l % p] |= (G[l] | F[y][l % p]);
        if(F[x][0]) return true;
        fa[y] = fa[x] = x;
    }
    return false;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> p;
    A.assign(n + 1, {});
    rep(i, 1, n) cin >> A[i].x >> A[i].y >> A[i].v, A[i].v %= p;
    sort(A.begin() + 1, A.end(), [](const Node &x, const Node &y) {
        return (x.x == y.x ? x.y < y.y : x.x < y.x);
    });
    double l = 0, r = 1e8 * sqrt(2) + 1;
    double ans = 0;
    while(r - l > eps) {
        double mid = (l + r)/ 2;
        if(check(mid)) r = mid, ans = mid;
        else l = mid;
    }
    cout << fixed << setprecision(3) << ans << '\n';
    return 0;
}
/*
求最大距离最小，考虑二分
可以考虑处理余数。
*/