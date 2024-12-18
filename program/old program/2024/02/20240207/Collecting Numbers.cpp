//Collecting Numbers  CSES - 2216
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
    vector<bool> s(n + 1);
    int c =0 ;
    for(int i = 1, a; i <= n; i++) {
        cin >> a;
        c += !s[a - 1], s[a] = true;
    }
    cout << c << '\n';
    return 0;
}
