// Notebook
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string op;
    int idx = 0, it = 0;
    vector<int> val(n + 1), fa(n + 1);
    unordered_map<int, int> bk;
    for(int x; n-- && cin >> op; ) {
        if(op[0] == 'D') {it = fa[it];}
        else cin >> x;
        if(op[0] == 'A') {
            fa[++idx] = it;
            it = idx, val[idx] = x;
        }
        if(op[0] == 'S') {
            bk[x] = it;
        }
        if(op[0] == 'L') {
            it = bk[x];
        }
        cout << (it == 0 ? -1 : val[it]) << " ";
    }
    return 0;
}