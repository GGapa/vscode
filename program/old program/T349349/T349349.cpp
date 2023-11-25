#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define int unsigned long long
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        int a[n];
        long long mu = 1;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            mu *= (long long)(a[i]);
        }
        long long g = a[1], l = a[1];
        for (int i = 2; i <= n; i++)
        {
            g=gcd(g,a[i]);
            l=lcm(l,a[i]);
        }
        if(l*g==mu)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}