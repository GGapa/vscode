//Marks Distribution 
#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL C(LL n, LL k) {
    if (k < 0)  return 0;
    k = min(k, n - k);
    LL c = 1;
    for (LL i = 0; i < k; i ++ )  c = c * (n - i) / (i + 1);
    return c;
}
int main() {
    ios :: sync_with_stdio(false), cin.tie(0);
    int T;
    cin >> T;
    for (LL n, k, p; T --  && cin >> n >> k >> p;)  k -= n * p, cout << C(n + k - 1, k) << endl;
    return 0;
}