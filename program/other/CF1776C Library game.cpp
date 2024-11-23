#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> A(n + 1) ;
    rep(i, 1, n) cin >> A[i];
    sort(A.begin() + 1, A.end(), greater<>());
    int mn = 0;
    rep(i ,1, n) if(A[i] > m / i) {mn = A[i]; break;}
    if(mn == 0) {
        cout << "Alessia" << endl;
        using AI = array<int, 2> ;
        priority_queue<AI> q;
        q.push({m, 1}) ;
        rep(i, 1, n) {
            int l = q.top()[1], r = l + q.top()[0] - 1; q.pop();
            cout << A[i] << " " << l << endl;
            int x; cin >> x;
            if(x - l) q.push({x - l, l}); 
            if(r - x) q.push({r - x, x + 1});
        }
    } 
    else {
        cout << "Bernardo" << endl;
        vector<int> vis(m + 1) ;
        vis[0] = 1;
        bool tag = 0;
        rep(i, 1, n) {
            int l, len; cin >> len >> l;
            int r = l + len - 1;
            if(tag) {
                cout << l << endl;
                continue;
            }
            rep(j, l, r) if(vis[j]) {
                tag = 1;
                cout << j << endl;
                break;
            }
            if(tag) continue;
            int L = l - l % mn, R = r + (mn - r % mn) % mn;
            int it = 0;
            for(int j = L; j <= R; j += mn) if(l <= j && j <= r) {
                it = j;
                break;
            }
            cout << (it ? it : l) << endl;
        }
    } 
    return 0;
}