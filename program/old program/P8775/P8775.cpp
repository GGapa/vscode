// P8775 [蓝桥杯 2022 省 A] 青蛙过河
#include <iostream>
#include <cstdio>
using namespace std;
#define int long long
int n, x;
int map[100005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    x <<= 1;
    for (int i = 1; i < n; i++)
        cin >> map[i];
    int j = 0, sum = 0, ans = 0;
    for (int i = 1; i < n; i++)
    {
        while (j < n && sum < x)
            sum += map[j++];
        ans = max(ans, j - i + 1);
        sum -= map[i];
    }
    cout << ans << endl;
    return 0;
}