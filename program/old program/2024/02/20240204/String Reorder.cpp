#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

int n, a[30];
string s;

bool check(int len, int it) {
    if(a[it] > (len + 1) / 2) return false;
    rep(i, 0, 26)
        if(it != i && a[i] > len / 2) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    for(auto c : s)
        a[c - 'A']++;
    string ans;
    for(int i = 0, la = -1; i < s.size(); i++) {
        bool tag = true;
        rep(j, 0, 26) {
            if(j != la && a[j] > 0 && check(s.size() - i, j)) {
                la = j;
                ans += (char)('A' + j);
                a[j]--;
                tag = false;
                break;
            }
        }
        if(tag) {
            cout << -1 << '\n';
            return 0;l
        }
    }
    cout << ans;
    return 0;
}