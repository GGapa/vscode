#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)

string a, b;
int n;

void solve() {
    int cnt = 0, c0 = 0, c1 = 0;
    cin >> n;
    cin >> a >> b;
    for(int i = 0; i < n; i++) {
        if(a[i] == '0' && b[i] == '1') c0++;
        if(a[i] == '1' && b[i] == '0') c1++;
    }
    if(c0 < c1) swap(c0, c1);
    int ans = c0-c1+min(c0, c1);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    rep(_, 1, T) solve();
}