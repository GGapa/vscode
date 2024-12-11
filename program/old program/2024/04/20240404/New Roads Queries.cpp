// New Roads Queries CSES - 2101 
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using VI = vector<int>;
typedef long long ll;
const int N = 2e5 + 5, INF = 1e9;


int F[N], T[N];
int find(int x) {return (F[x] < 0 ? x : find(F[x]));};
void merge(int x, int y, int cnt) {
    x = find(x), y = find(y);
    if(x == y) return ;
    if(-F[x] > -F[y]) swap(x, y);
    F[y] += F[x], F[x] = y, T[x] = cnt;
}

int ask(int x, int y) {
    int cnt = -1;
    while(x != y) {
        int &t = T[x] < T[y]  ? x : y;
        cnt = T[t], t = F[t];
        if(cnt == INF) return -1;
    }
    return cnt;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, q; cin >> n >> m >> q;
    fill_n(F, n + 1, -1), fill_n(T, n + 1, INF);
    for(int i = 1, x, y; i <= m; i++) 
        cin >> x >> y, merge(x, y, i);
    for(int i = 1, x, y; i <= q; i++) 
        cin >> x >> y, cout << (x == y ? 0 : ask(x, y)) << '\n';
    
    return 0;
}