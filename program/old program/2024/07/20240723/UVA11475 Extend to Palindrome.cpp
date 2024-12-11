#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 2e5 + 5;

string tmp;
int R[N];

void solve() {
    string s = "@|";
    for(auto c : tmp) s += c, s += "|";
    s += "!";
    int n = s.size() - 1;
    int l = n - 1;
    fill(R, R + 1 + n, 0);
    // cout << s << '\n';
    for(int i = 1, c = 0, r = 0; i < n; i++) {
        int &j = R[i] = i > r ? 1 : min(R[2 * c - i], r - i + 1);
        while(s[i - j] == s[i + j]) j++;
        if(i + j - 1 == n - 1) l = min(l, i - j + 1);
        if(i + j - 1 > r) c = i, r = i + j - 1;
        // cout << R[i] << " \n"[i == n - 1];
    }
    string ans, t;    
    rep(i, 1, l) if(s[i] != '|') ans += s[i];
    rep(i, l + 1, n - 1) if(s[i] != '|') t += s[i];
    cout << ans + t + string(ans.rbegin(), ans.rend()) << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(; cin >> tmp; ) solve()    ;
    return 0;
}