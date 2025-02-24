#include <bits/stdc++.h>
#include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string s; cin >> s; s = " " + s;
    vector<char> stk;
    int cnt = 0;

    for(int i = 1; i <= n; i++) {
        stk.emplace_back(s[i]);
        int m = stk.size() - 1;
        while(m >= 2 && stk.back() == 'x' && stk[m - 1] == 'o' && stk[m - 2] == 'f') {
            rep(i, 0, 2) stk.pop_back(), m--, cnt++;
        }
    }

    cout << n-  cnt << '\n';

    return 0;
}