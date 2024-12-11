// P6182 
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
    for(int x, i = 2; n-- && cin >> op; i++) {
        if(op[0] == 's') {it = fa[it];}
        else cin >> x;
        if(op[0] == 'a') {
            fa[++idx] = it;
            it = idx, val[idx] = x;
        }
        if(op[0] == 't') {
            it = bk[x];
        }
        bk[i] = it;
        cout << (it == 0 ? -1 : val[it]) << '\n';
    }
    return 0;
}