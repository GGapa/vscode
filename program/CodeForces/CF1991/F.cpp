#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 1e5 + 5;

int A[N], a[N];

bool check(int l, int r) {
    int t = 0;
    rep(i, l, r) A[++t] = a[i];
    sort(A + 1, A + 1 + t);
    rep(i, 1, t - 5)
        rep(j, i + 1, i + 5)  
            rep(k, j + 1, i + 5) {
                int c = 0;
                vector<int> tt(5);
                for(int q = i + 1; q <= i + 5; q++) if(q != k && q != j) tt[++c] = A[q];
                if(A[i] + A[j] > A[k] && tt[1] + tt[2] > tt[3]) 
                    return true;
            }
    int cnt = 0;
    rep(i, 1, t - 2) {
        if(A[i] + A[i + 1] > A[i  +2]) cnt++, i += 2;
    }
    return cnt > 1;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    rep(i ,1, n) cin >> a[i];
    for(int i = 1, l, r; i <= q; i++) {
        cin >> l >> r;
        if(r - l + 1 >= 50 || check(l, r)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}