#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n = 400, m = 800, q = 100;
int main() {
    freopen("b.in", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << n << ' ' << m << '\n';
    for (int i = 2; i <= n; i++) cout << i - 1 << " \n"[i == n];
    for (int i = 2; i <= m; i++) cout << i - 1 << " \n"[i == m];
    cout << q << '\n';
    for (int i = 1; i <= q; i++) {
        cout << "1 " << i << '\n';
    }
    return 0;
}