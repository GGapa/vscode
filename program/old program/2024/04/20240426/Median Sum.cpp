// Median Sum
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, sum = 0; cin >> n;
    bitset<2010 * 2010> A;
    A[0] = 1;
    for(int i = 1, x; i <= n; i++) {
        cin >> x;
        A |= A << x;
        sum += x;
    }
    rep(i, (sum + 1) / 2, sum) if(A[i]) 
        return cout << i << '\n' ,0;
    return 0;
}