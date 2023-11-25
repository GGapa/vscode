// P8707 [蓝桥杯 2020 省 AB1] 走方格
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[35][35], n, m;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        a[i][1] = 1;
    for (int i = 1; i <= m; i++)
        a[1][i] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= m; j++)
        {
            if(!(i%2==0&&j%2==0))
            {
                a[i][j]=a[i][j-1]+a[i-1][j];
            }
        }
    }
    printf("%d",a[n][m]);
    return 0;
}