// P1592 互质
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n, k, total, a[1000005];
void debug()
{
    for (int i = 0; i < total; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main()
{
    scanf("%d%d", &n, &k);
    if (n == 1)
    {
        cout << k << endl;
        return 0;
    }
    for (int i = 1; i < n; i++)
    {
        if (__gcd(i, n) == 1)
            a[++total] = i;
    }
    printf("%d",(k-1)/total*n+a[(k-1)%total+1]);
    return 0;
}