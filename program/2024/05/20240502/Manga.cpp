// Manga
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
    vector<int> A(n + 1), bk(n + 2);
    rep(i, 1, n) cin >> A[i];
    rep(i, 1, n) if(A[i] <= n) bk[A[i]] = 1;
    rep(i, 1, n + 1) bk[i] += bk[i - 1];
    rep(i, 1, n + 1) {
        if(i - bk[i] > (n - bk[i]) / 2) return cout << i - 1, 0;
    }
    return 0;
}