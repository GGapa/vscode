// T270955 『JROI-8』雷雨天特别行动科
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("in.in","r",stdin);
	freopen("in2.out","w",stdout);
    long long x, k;
    int ans[3]={1,2,3};
    scanf("%lld %lld", &x, &k);
    while (k--)
    {
        x++;
        if (x % 3 == 0)
        {
            x /= 3;
        }
    }
    printf("%lld",x);
}
