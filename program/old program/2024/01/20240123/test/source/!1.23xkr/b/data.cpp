#include<bits/stdc++.h>
using namespace std;
int n = 400, m = 800, q = 100;
int main() {
    freopen("b.in", "w", stdout);
    cout << n << ' ' << m << endl;
    for (int i = 2; i <= n; i++) cout << i - 1 << ' ';
    cout << '\n';
    for (int i = 2; i <= m; i++) cout << i - 1 << ' ';
    cout << '\n';
    cout << q << endl;
    for (int i = 1; i <= q; i++) cout << 1 << ' ' << i << endl;
    return 0;
}
