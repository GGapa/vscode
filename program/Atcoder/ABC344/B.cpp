#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> a;
    for(int x = 1; cin >> x && x;) 
        a.push_back(x);
    cout << "0\n";
    reverse(a.begin(), a.end());
    for(auto i : a) cout << i << '\n';
    return 0;
}