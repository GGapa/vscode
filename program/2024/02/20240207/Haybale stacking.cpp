//Haybale stacking
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
    while(q--) {
        int l, r; cin >> l >> r;
        a[l]++; 
        a[r + 1]--;
    }
    rep(i, 1, n) a[i] += a[i - 1];
    sort(a.begin(), a.end());
    cout << a[(1 + n) / 2] << '\n';
    return 0;
}