// P6013 [CSGRound3]压岁钱
#include <iostream>
#include <cstdio>
#include <queue>
#include <map>

using namespace std;

long long wait[1000001];

int main()
{
    long long total = 0;
    long long m, ans = 0;
    scanf("%lld", &m);
    for (long long i = 1; i <= m; i++)
    {
        long long t;
        scanf("%lld", &t);
        total+=wait[i];
        if (t == 1)
        {
            long long input;
            scanf("%lld", &input);
            total += input;
        }
        if (t == 2)
        {
            long long a;
            scanf("%lld", &a);
            if (a > total)
                ans++;
            else
                total -= a;
        }
        if (t == 3)
        {
            long long a, b;
            scanf("%lld%lld", &a, &b);
            total -= a;
            wait[b]+=a;
        }
    }
    printf("%lld", ans);
    return 0;
}