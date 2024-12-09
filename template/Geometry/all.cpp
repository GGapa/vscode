#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr double eps = 1e-6;

int dcmp(double x) {return x < -eps ? -1 : x > eps;}
struct Node {
    double x, y;
    Node(double x = 0, double y = 0) : x(x), y(y) {}
    Node operator+(Node b) { return Node(x + b.x, y + b.y); }
    Node operator-(Node b) { return Node(x - b.x, y - b.y); }
    Node operator*(double p) { return Node(x * p, y * p); }
    Node operator/(double p) { return Node(x / p, y / p); }
    double operator*(Node b) { return x * b.x + y * b.y; }
    double operator^(Node b) { return x * b.y - y * b.x; }
    double len() { return sqrt(*this * *this); }
    bool operator<(Node b) const {
        return !dcmp(x - b.x) ? dcmp(y - b.y) < 0 : dcmp(x - b.x) < 0;
    }
    bool operator==(Node b) {
        return !dcmp(x - b.x) && !dcmp(y - b.y);
    }
    Node rot(double p) {
        return Node(x * cos(p) - y * sin(p), x * sin(p) + y * cos(p));
    }
    void read() {
        cin >> x >> y;
    }
};

bool toRight(Node p, Node a, Node b) {
  return dcmp((p - a) ^ (b - a)) > 0;
}
bool onLine(Node p, Node a, Node b) {
    return dcmp((p - a) ^ (b - a)) == 0;
}
Node foot(Node p, Node a, Node b) {
    Node l = b - a;
    return a + l * (((p - a) * l) / (l * l));
}

using VP = vector<Node>;

VP convexHull(VP &A) {
    assert(A.size() != 0);
    int n = (int)A.size() - 1, m = 0;
    if(n <= 1) return A;
    sort(A.begin() + 1, A.end());
    VP B(2 * n + 2);
    for(int i = 1; i <= n; B[++m] = A[i++]) 
        while(m > 1 && ((A[i] - B[m - 1]) ^ (B[m] - B[m - 1])) >= 0) m--;
    for(int i = n, t = m; i >= 1; B[++m] = A[i--]) 
        while(m > t && ((A[i] - B[m - 1]) ^ (B[m] - B[m - 1])) >= 0) m--;
    B.resize(m);   
    return B;
}

constexpr int N = 105;

int n;
Node A[N], B[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    rep(i, 1, n) A[i].read(), B[i].read();
    int q; cin >> q;
    while (q--) {
        Node a; a.read();
        set<Node> s; s.insert(a);
        per(i, n, 1) {
            Node a = A[i], b = B[i];
            set<Node> t;
            for (auto p : s) {
                if (toRight(p, a, b) || onLine(p, a, b)) continue;
                t.insert(p);
                t.insert((foot(p, a, b) * 2) - p);
            }
            s = t;
        }
        int ans = 0;
        for (auto p : s) 
            if (dcmp(p.x) > 0 && dcmp(p.x - 100) < 0 && dcmp(p.y) > 0 && dcmp(p.y - 100) < 0) 
                ans++;
        cout << ans << '\n';
    }
    return 0;
}
