#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N = 70;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll a, b, c; cin >> a >> b >> c;
    auto getlen = [&](int x) {
        int cnt = 0;
        while(x) {
            cnt++;
            x >>= 1;
        }
        return cnt;
    };
    bitset<N> A, B, C = c;
    int lc = getlen(c);
    for(int i = 0; i < lc; i++) {
        if(C[i] == 1) {
            if(a > b) a--, A[i] = 1;
            else if(a <= b) b--, B[i] = 1;
            else return cout << "-1\n", 0;
        }
    }
    rep(i, 0, 59) {
        if(C[i] == 0) {
            if(a > 0 && b > 0) a--, b--, A[i] = B[i] = 1;
        }
    }
    if(a != 0 || b != 0) return cout << "-1\n", 0;
    cout << A.to_ullong() << " " << B.to_ullong() << '\n';
    return 0; 
}