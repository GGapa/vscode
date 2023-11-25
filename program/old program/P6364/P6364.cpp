#include <iostream>
#include <cstdio>
#include <limits.h>
#include <algorithm>
using namespace std;
int a[1000006], n,f[1000006];
long long ans = 0;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]),f[i]=1;
    f[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i - 1] < a[i])
            f[i] = f[i - 1] + 1;
        if (a[i - 1] == a[i])
            f[i] = f[i - 1];
    }
    for (int i = n; i >= 2; i--)
    {
        if (a[i] < a[i - 1])
            f[i - 1] = max(f[i - 1], f[i] + 1);
        if (a[i - 1] == a[i])
            f[i - 1] = f[i];
    }
    for (int i = 1; i <= n; i++)
        ans += f[i];
    cout << ans << endl;
    return 0;
}