#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = s.size();
    set<string> st;
    s = " " + s;
    for(int l = 1; l <= n; l++) for(int i = 1; i + l <= n + 1; i++) {
        st.insert(s.substr(i, l));
    }
    cout << st.size() << '\n';
    return 0;
}