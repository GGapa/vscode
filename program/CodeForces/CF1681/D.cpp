#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
#define int long long
using LL = long long;
using VI = vector<int>;

int n;
int ans = INT_MAX;

void dfs(LL x, int cnt) {
    string s = to_string(x);
    int t = s.size();
    if(cnt + n - t >= ans) return ;
    if(s.size() == n) return ans = min(ans, cnt), void();
    set<char> st;
    for(auto c : s)  st.insert(c);
    for(auto i = st.rbegin(); i != st.rend(); i++) {
        LL tt = *i - '0';
        if(tt > 1) dfs(x * tt, cnt + 1);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int x; cin >> n >> x;
    if(x == 1) return cout << -1 << '\n', 0;
    dfs(x, 0);
    if(ans >= INT_MAX) ans = -1;
    cout << ans << '\n';
    return 0;
}