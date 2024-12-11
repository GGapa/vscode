// P9455 [入门赛 #14] 塔台超频 (Hard Version)
#include <iostream>
using namespace std;
const int maxn = 5e5 + 5;
int n, ans, a[maxn], b[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    for (int i = 1; i < n; i++)
    {
        if (a[i] + b[i] + ans >= a[i + 1] + b[i + 1] + ans)
        {
            a[i + 1] = a[i], b[i + 1] = b[i];
            continue;
        }
        if (a[i] + b[i] + ans >= a[i + 1])
            continue;
        ans = a[i + 1] - a[i] - b[i];
    }
    cout << ans << endl;
    return 0;
}
