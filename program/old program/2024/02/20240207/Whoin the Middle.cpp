//Who's in the Middle 
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for(auto & i : a) cin >> i;
    sort(a.begin(), a.end());
    cout << a[n / 2] << '\n';
    return 0;
}
