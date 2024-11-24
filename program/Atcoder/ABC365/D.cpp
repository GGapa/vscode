#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

// 石头剪刀布
int win[3][3] = {
    {0, 1, -1}, 
    {-1, 0, 1},
    {1, -1, 0},
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> A(n + 1);
    rep(i, 1, n) {
        char c; cin >> c;
        if(c == 'R') A[i] = 0;
        else if(c == 'P') A[i] = 2;
        else A[i] = 1;
    }
    
    vector<VI> F(n + 1, VI(4)); 
    rep(i, 1, n) rep(j, 0, 2) {
        rep(k, 0, 2) if(j != k && win[k][A[i]] >= 0) {
            F[i][k] = max(F[i][k], F[i - 1][j] + win[k][A[i]]);
        }
    }
    // rep(i, 1, n) rep(j, 0, 2) cout << F[i][j] << " \n"[j == 2];
    cout << *max_element(F[n].begin(), F[n].end()) << '\n';
    return 0;
}