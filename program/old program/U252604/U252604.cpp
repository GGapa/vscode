#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
bool f = false;
int n, fuhao;
long long up = 0, down = 0, inon, indown;
inline void gcd()
{
    long long x = __gcd(up, down);
    if (up*1.0 / down != 1)
    {
        while (x != 1)
        {
            up /= x;
            down /= x;
            x = __gcd(up, down);
        }
    }
    else
    {
        up=down=1;
    }
}
inline void add()
{
    if (up == down && down == 0)
    {
        up = inon;
        down = indown;
    }
    else if (fuhao == 1)
    {
        inon *= down;
        up *= indown;
        down *= indown;
        up += inon;
        gcd();
    }
    else
    {
        inon *= down;
        up *= indown;
        down *= indown;
        up -= inon;
        gcd();
    }
    if (up * down < 0)
        f = true;
    else
        f = false;
}
int main()
{
    scanf("%d", &n);
    while (n--)
    {
        scanf("%lld %lld %d", &inon, &indown, &fuhao);
        add();
    }
    if (up % down == 0)
        printf("%lld", up / down);
    else
    {
        up = abs(up);
        down = abs(down);
        if (f == false)
        {
            printf("%lld/%lld", up, down);
        }
        else
        {
            printf("-%lld/%lld", up, down);
        }
    }
    return 0;
}