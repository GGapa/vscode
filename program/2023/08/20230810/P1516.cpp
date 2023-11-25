/// P1516 青蛙的约会
// https://www.luogu.com.cn/problem/P1516
#include <iostream>
using namespace std;
typedef long long ll;
ll ans;
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    ans = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return ans;
}

ll x, y, m, n, L;
int main()
{
    cin >> x >> y >> m >> n >> L;
    ll b = n - m;
    ll a = x - y;
    if (b < 0)
    {
        b = -b;
        a = -a;
    }
    ll x1, y1;
    exgcd(b, L, x1, y1);
    if (a % ans != 0)
    {
        cout << "Impossible";
        return 0;
    }
    cout << ((x1 * (a / ans)) % (L / ans) + (L / ans)) % (L / ans);
    return 0;
}