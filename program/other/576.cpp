#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 100000 * 2 + 5;

int F[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s, tmp; cin >> tmp ;
    s += "@|" ;
    for(auto c : tmp) s += c, s += "|";
    s += "#";
    int n = (int)s.size() - 1;
    int ans = 0;
    for(int i = 1, c = 0, r = 0; i < n; i++) {
        int &j = F[i] = r < i ? 1 : min(F[c * 2 - i], r - i + 1);
        while(s[i - j] == s[i + j]) j++;
        ans = max(ans, j - 1);
        if(i + j - 1 > r) r = i + j - 1, c = i;
    }
    cout << ans << '\n';
    return 0;
}