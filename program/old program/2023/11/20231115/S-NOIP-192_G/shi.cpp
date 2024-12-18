#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 5e5 + 5;
typedef pair<int, int> pii;

int T, n, m;
int fa[maxn], ans[maxn];
bool used[maxn];

struct Node {
    int u, v, l, r, id;
}a[maxn];

int find(int x) {
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void solve() {
    memset(used, 0, sizeof(used));
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for(int i = 1; i <= m; i++) q.push(make_pair(a[i].r, i));
    for(int i = 1; i <= n; i++) fa[i] = i;
    while(!q.empty()) {
        bool flag = false;
        int x = q.top().second, val = a[x].l; q.pop();
        while(used[val] && val <= a[x].r) val++, flag = true;
        cout << q.size() << endl;
        if(val > a[x].r) {
            cout << "NO\n";
            return ;
        }
        int A = find(a[x].u), B = find(a[x].v);
        if(a[x].id >= n) {
            if(A == B) {
                used[val] = true;
                ans[a[x].id] = val;
            }
            else {
                q.push(make_pair(flag ? val : val + 1, x));
            }
        }
        else {
            if(A == B) {
                cout << "NO\n";
                return ;
            }
            else {
                used[val] = true;
                ans[a[x].id] = val;
                fa[A] = B;
            }
        }
    }
    cout << "YES\n";
    for(int i = 1; i <= m; i++) cout << ans[i] << " \n"[i == m];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("shi.in", "r", stdin);
    freopen("shi.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--) {
        cin >> n >> m;
        for(int i = 1; i <= m; i++) 
            cin >> a[i].u >> a[i].v >> a[i].l >> a[i].r, a[i].id = i;
        sort(a + 1, a + 1 + m, [](const Node& x, const Node& y) {
            if(x.r == y.r) return x.l < y.l;
            return x.r < y.r;
        });
        solve();
    }
    return 0;
}   