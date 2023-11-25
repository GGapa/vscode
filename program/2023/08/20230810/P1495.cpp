// P1495 【模板】中国剩余定理（CRT）/ 曹冲养猪
// https://www.luogu.com.cn/problem/P1495
#include <iostream>
#include <limits.h>
using namespace std;
const int maxn = 100000 + 5;
#define ll long long
inline int read()
{
    char c;
    int f = 1, x = 0;
    c = getchar();
    while (!isdigit(c))
    {
        if (c == '-')
        {
            f = -1;
        }
        c = getchar();
    }
    while (isdigit(c))
    {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return f * x;
}
void exgcd(ll a, ll b, ll &x, ll &y)
{
    if (a % b == 0)
        x = 0, y = 1;
    else
        exgcd(b, a % b, y, x), y -= a / b * x;
}
int inv(long long x, long long y)
{
    long long A, B;
    exgcd(x, y, A, B);
    return (A % y + y) % y;
}
int n;
int a[maxn], b[maxn]; // mod       ≡
long long t[maxn];
long long sum = 1;
signed main()
{

    n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        b[i] = read();
        sum *= a[i];
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        t[i] = sum / a[i];
        ans += ((t[i] * inv(t[i], a[i]))* b[i]) % sum;
    }
    cout << ans % sum << endl;
    return 0;
}