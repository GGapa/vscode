// Line
// https://www.luogu.com.cn/problem/CF7C
// https://codeforces.com/problemset/problem/7/C
#include <iostream>
using namespace std;
typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll tmp = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return tmp;
}
ll a, b, c, x, y;
int main()
{
    cin >> a >> b >> c;
    c = -c;
    int gcd = exgcd(a, b, x, y);
    if (c % gcd != 0)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << c / gcd * x << " " << c / gcd * y << endl;
}