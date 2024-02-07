//Block Game
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

int n;
int f1[30], f2[30];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n) {
        string s1, s2;
        cin >> s1 >> s2;
        memset(f1, 0, sizeof(f1)); memset(f2, 0, sizeof(f2));
        for(char c : s1) f1[c - 'a']++;
        for(char c : s2) f2[c - 'a']++;
        rep(i, 0, 26) ans[i] += max(f1[i], f2[i]);
    }
    rep(i, 0, 25) cout << ans[i] << '\n';
    return 0;
}