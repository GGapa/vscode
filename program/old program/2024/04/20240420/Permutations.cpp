// Permutations 
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
    if(n == 1) return cout << 1 << "\n", 0;
    if(n <= 3) return cout << "NO SOLUTION\n", 0;
    for(int i = 2; i <= n; i+= 2) cout << i << " ";
    for(int i = 1; i <= n; i += 2) cout << i << " ";
    return 0;
}