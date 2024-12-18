//Trailing Zeros
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int c2, c5; c2 = c5 = 0;
    c2 = INT_MAX;
    // for(ll p = 2; p <= n; p *= 2) c2 += n / p;
    for(ll p = 5; p <= n; p *= 5) c5 += n / p;
    cout << min(c2, c5) << '\n';
    return 0;
}