//Ferris Wheel 
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    int ans = 0;
    sort(a.begin(), a.end());
    for(int i = 1, j = n; i <= j; i ++) {
        while(i < j && a[i] + a[j] > x) j--, ans++;
        while(i < j && a[i] + a[j] <= x) i++, j--, ans++;
        if(i == j) ans++;
    }
    cout << ans << '\n';
    return 0;
}