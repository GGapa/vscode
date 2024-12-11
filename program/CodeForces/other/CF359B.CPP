#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;

int n, k;

void solve()  {
    cin >> n >> k;
    n <<= 1;
    cout << k + 1 << " ";
    rep(i, 1, n) if(i != k + 1) cout << i <<" \n"[i == n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}

// 1 2 3 4 5 6 7 8
// 3 1 2 4