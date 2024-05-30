#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for (int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 3e5 + 5;


    ll n, ans;
    ll a[N], s[N];
    int main()
    {
        n = read();
        for (int i = 1; i <= n; i++)
            a[i] = read();
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++)
            s[i] = s[i - 1] + a[i];
        for (int i = 2; i <= n; i++)
        {
            ll t = upper_bound(a + 1, a + i, mod - a[i] - 1) - (a + 1);
            ans += s[i - 1] + (i - 1) * a[i] - (i - t - 1) * mod;
        }
        write(ans);
        return 0;
    }
    return 0;