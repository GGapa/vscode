#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;

int n, m, k;

void solve() {
    cin >> n >> m >> k;
    int x = 1, y = 1;
    rep(i, 2, k) {
        cout << "2 ";
        rep(j, 1, 2) {
            cout << x << " " << y << " ";
            if(x & 1) y++;
            else y--;
            if(y > m) x++, y--;
            if(!y) y++, x++;
        }
        cout << '\n';
    }
    cout << (n * m - 2 * (k - 1)) << ' ';
    while(x != n + 1) {
        cout << x << " " << y << " ";
        if(x & 1) y++;
        else y--;
        if(y > m) x++, y--;
        if(!y) y++, x++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}