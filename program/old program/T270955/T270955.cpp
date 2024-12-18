// T270955 『JROI-8』雷雨天特别行动科
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    long long x, k;
    int ans[3]={1,2,3};
    freopen("in.in","r",stdin);
    freopen("in1.out","w",stdout);
    scanf("%lld %lld", &x, &k);
    while (k--)
    {
        x++;
        if (x % 3 == 0)
        {
            x /= 3;
        }
        if (x == 1)
        {
            printf("%d", ans[k % 2]);
            return 0;
        }
    }
    printf("%lld",x);
}