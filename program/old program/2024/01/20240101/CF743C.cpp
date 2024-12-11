#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;

int x, y, z, n;
double num;


void solve() {
    cin >> n;
    if(n == 1) cout << -1;
    else cout << n << " " << n + 1 << " " << 1ll * n * (n + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}