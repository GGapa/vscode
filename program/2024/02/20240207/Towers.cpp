//TowersCSES - 1073 
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
    multiset<int> s;
    rep(i, 1, n) {
        int x; cin >> x;
        auto it = s.upper_bound(x);
        it == s.end() ? (s.insert(x)) : (s.erase(it), s.insert(x));
    }
    cout << s.size() << '\n';
    return 0;
}