// P2034 选择数字(90pts 待解决)
#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
priority_queue<long long> q;
long long a[100005] = {0}, ans = 0, n, k, f[100005];
int main()
{
    //cin >> n >> k;
    scanf("%lld %lld",&n,&k);
    for (int i = 1; i <= n; i++)
    {
        //cin >> a[i];
        scanf("%lld",&a[i]);
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n+1; i++)
    {
        for (int j = max((long long)0, i - k - 1); j < i; j++)
        {
            f[i] = max(f[i], f[j] + a[i - 1] - a[j]);
        }
    }
    cout << f[n+1] << endl;
}