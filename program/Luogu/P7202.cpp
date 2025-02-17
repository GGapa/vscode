#include <bits/stdc++.h>
// #include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
// using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    string s; cin >> s;
    vector<AI<3>> ans;
    vector<int> cnt(3), nxt(n + 1), col(n + 1);
    {
        LL sum = 0;
        for(auto c : s) sum ^= (c - '0'), cnt[c - '0']++;
        rep(i, 0, n - 1) nxt[i] = (i + 1) % n, col[i] = s[i] - '0';
        if(*max_element(cnt.begin(), cnt.end()) == n || sum) return cout << "NE\n", 0;
    }
    for(int i = 0, x = 0, y; i < n - 3; i++) {
        while(col[x] == col[nxt[x]] || (cnt[col[x]] == 1 && cnt[col[nxt[x]]] == 1)) x = nxt[x];
        y = nxt[x];
        cnt[col[x]]--; cnt[col[y]]--;
        cnt[col[x] ^ col[y]]++;
        nxt[x] = nxt[y];
        col[x] = col[x] ^ col[y];
        ans.push_back({x, nxt[x], col[x]});
    }
    cout << "DA\n";
    for(auto [a, b, c] : ans) cout << a + 1 << " " << b + 1<< " " << c << '\n';

    return 0;
}