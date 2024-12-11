// P5425 [USACO19OPEN] I Would Walk 500 Miles G
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int NN = 7501;
int N, K, Vis[NN];
#define _all(i, a, b) for (int i = (a); i <= (int)(b); ++i)
using LL = long long;
const LL MOD = 2019201997, A = 2019201913LL, B = 2019201949LL;
LL D[NN];
LL prim() { 
    fill_n(D, N + 1, MOD);
    _all(iter, 1, N)
    {
        int mi = 0;
        _all(i, 1, N) if (!Vis[i] && (mi == 0 || D[i] < D[mi])) mi = i;
        Vis[mi] = 1;
        _all(i, 1, N) if (!Vis[i]) D[i] =
            min(D[i], (A * min(mi, i) + B * max(mi, i)) % MOD);
    }
    sort(D + 1, D + N + 1);
    return D[N + 1 - K];
}
signed main(void) {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> N >> K;
    cout << prim() << "\n";
    return 0;
}