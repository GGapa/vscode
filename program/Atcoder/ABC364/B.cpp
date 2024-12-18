#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<string> A(n + 1);
    int x = 1, y = 1;
    cin >> x >> y;
    rep(i ,1, n) cin >> A[i], A[i] = " " + A[i]; 
    string s; cin >> s;
    for(auto c : s) {
        int nx= x, ny = y;
        if(c == 'U') nx--;
        else if(c == 'D') nx++;
        else if(c == 'R') ny++;
        else ny--;
        if(nx < 1 || ny < 1 || nx > n || ny > m || A[nx][ny] == '#') continue;
        x = nx, y = ny;
    }
    cout << x << " " << y << '\n';
    return 0;
}