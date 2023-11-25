// P2642 双子序列最大和
//此做法存在問題，已廢棄。
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define maxn 1000005
long long a[maxn], ans[maxn], num = 0;
bool use = false;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= 0)
        {
            ans[num] += a[i];
            use=true;
        }
        else
        {
            ans[++num]=a[i];
            num++;
        }
    }
    sort(ans, ans + num);
    if(use)cout << ans[num - 1] + ans[num - 2] << endl;
    return 0;
}