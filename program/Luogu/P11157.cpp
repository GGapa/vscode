#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> A(n + 2), pos(n + 2);
    rep(i, 1, n) cin >> A[i], A[i] -= i;    
    pos[n] = n;
    per(i, n - 1 , 1) pos[i] = (A[i] > A[pos[i + 1]] ? i : pos[i + 1]);

    // rep(i, 1, n) cerr << pos[i] << " \n"[i == n];
    rep(i, 1, n) {
        if(A[i] + i + i > n || -i > A[pos[max(1, A[i] + i + i)]])  cout << 0 << '\n';
        else cout << 1 << " " << pos[max(1, A[i] + i + i)] - i << "\n";
    }
    return 0;
}