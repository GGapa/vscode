#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, a, b; cin >> n >> a >> b;
    vector<int> A;
    for(int i = 1, d; i <= n; i++) {
        cin >> d;
        d = d % (a + b);
        A.push_back(d);
    }
    sort(A.begin(), A.end());
    int it = 0;
    while(A[it + 1] - A[0] < a && it + 1< n) it++;
    if(it == n - 1) return cout << "Yes\n", 0;
    int nit = it;
    while(A[it] == A[nit] && nit < n - 1) nit++;
    cout << (A[nit] - A[it] <= b ? "No\n" : "Yes\n");
    return 0;
}   