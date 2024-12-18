#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = s.size();
    int cnt = 0;
    per(i, n - 1, 0) {
        if(s[i] == '0') cnt++;
        else if(cnt) cnt--;
        else s[i] = '0';
    }
    cout << s << '\n';
    return 0;
}