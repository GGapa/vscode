#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    bool tag = true;
    
        rep(i, 1, s.size() - 2) if(s[i] != '=') {
            tag = false;
            break;
        }
    if(*s.begin() != '<' || *s.rbegin() != '>')  tag = false;
    cout << (tag ? "Yes" : "No");
    return 0;
}