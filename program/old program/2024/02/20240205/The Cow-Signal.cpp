//The Cow-Signal 
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

int n, m, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    rep(i, 1, n)    {
        string s;
        string ot;
        cin >> s;
        rep(j, 0, m - 1) {
            rep(q, 1, k) ot += s[j];
        }
        rep(q, 1, k) cout << ot << '\n';
    }
    return 0;
}