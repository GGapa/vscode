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

    string s, tmp; cin >>  tmp;
    s += "@|";
    for(auto c : tmp) s += c, s += '|';
    s += "#";
    int n = (int)s.size() - 1, ans = 0;
    vector<int> len(n + 1);
    for(int i = 1, c = 0, r = 0; i < n; i++) {
        int &j = len[i] = r < i ? 1 : min(len[c * 2 - i], r - i + 1);
        while(s[i - j] == s[i + j]) j++;
        ans = max(ans, j - 1);
        if(i + j - 1 > r) r = i + j - 1, c = i;
    }
    cout << ans << '\n';

    return 0;
}