#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e8 + 1;
int n, ans = 0;
bool a[maxn];
int main()
{
    scanf("%d", &n);
    for (int i = 2; i * i <= n; i++)
    {
        if (a[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
            {
                a[j] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!a[i])
            ans++;
    }
    printf("%d", ans - 1);
    return 0;
}