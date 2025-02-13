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

int n, m, top; 

struct Node {
    int x, y;
    Node operator-(Node a) {return {x - a.x, y - a.y}; }
    LL operator*(Node a) {return 1ll * x * a.y - 1ll * y * a.x; }
}A[N], B[N], S[N], P[N];

void conv(int &n, Node *s) {
    top = 0;
    rep(i, 1, n) {
        while (top > 1 && (P[i] - s[top - 1]) * (s[top] - s[top - 1]) >= 0)
            top--;
        s[++top] = P[i];
    }
    n = top;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    rep(i, 1, n) cin >> P[i].y, P[i].x = i;
    conv(n, A);
    rep(i, 1, m) cin >> P[i].y, P[i].x = i;
    conv(m, B);

    LL ans = 0;
    for(int i = 1, j = 1; i < n || j < m; ) {
        Node x = A[i + 1] - A[i], y = B[j + 1] - B[j];
        if(i < n && (j == m || x * y >= 0)) ans += 1ll * x.x * B[j].y, i++;
        else ans += 1ll * y.x * A[i].y, j++;
    }

    cout << ans << '\n';

    return 0;
}
