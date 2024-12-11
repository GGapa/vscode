//Range Xor Queries 
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1, x; i <= n; i++) {
        cin >> x; 
        a[i] = a[i - 1] ^ x;
    }
    for(int i = 1, l ,r; i <= q; i++) {
        cin >> l >> r;
        cout <<( a[r] ^ a[l - 1] )<< '\n';
    }
    return 0;
}






