#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

int n, q, c;
int a[N], tx[N], tn[N], mn[N];
pair<int, int> g[N];

void modifyn(int x, int v) {
    for(; x <= n; x += x & -x) tx[x] = max(tx[x], v);
}

int queryn(int x) {
    int tmp  = 0;
    for(; x; x -= x & -x) tmp = max(tx[x], tmp);
    return tmp;
}

void modifyx(int x, int v) {
    for(; x; x -= x & -x) tn[x] = min(tn[x], v);
}

int queryx(int x) {
    int tmp = INT_MAX;
    for(; x <= n; x += x & -x) 
        tmp = min(tn[x], tmp);
    return tmp;
}

void solve() {
    cin >> n >> q >> c;
    for(int i = 1; i <= n; i++ ){
        tx[i] = 0;
        tn[i] = INT_MAX;
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        mn[i] = (a[i] != 0 ? a[i] : 1);
        modifyn(i, (a[i] == 0 ? 1 : a[i]));    
    }
    for(int i = 1; i <= q; i++) 
        cin >> g[i].first >> g[i].second;
    bool tag = true;
    sort(g + 1, g + 1 + q);
    for(int i = 1, x, y; i <= q; i++) {
        x = g[i].first, y = g[i].second;
        int xn = queryn(x), yn = queryn(y - 1), xx = queryx(x), yx = queryx(y);
        if(xn < yn) {
            // if(yn <= xx) {
                for(int i = x; i >= 1; i--) {
                    if(a[i] != 0) continue;
                    if(yn > queryx(i)) break;
                    mn[i] = yn;
                    modifyn(i, mn[i]);
                    xn = yn;
                    break;
                }
                if(xn < yn) tag = false;
            // }
            // else {
            //     tag = false;
            // }
        }
        if(a[y] == 0) {
            if(xn + 1 > yx || xn + 1 > c) {
                tag = false;
            }
            mn[y] = xn + 1;
            modifyn(y, mn[y]);
            modifyx(y - 1, mn[y] - 1);
        }
        else {
            modifyx(y - 1, a[y] - 1);
        }
    }
    if(tag) for(int i = 1; i <= n; i++) cout <<(mn[i]) << " \n"[i == n];
    else cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
//Cowmpetency