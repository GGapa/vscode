// T344486 「SFCOI-3」进行一个魔的除
// https://www.luogu.com.cn/problem/T344486?contestId=118761
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int T, n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1, tmp; i <= n; i++)
        {
            cin >> tmp;
        }
        int ans = 0;
        ans += 1 + ceil(max(n - 6, 0) / 4);
        n /= 2;
        ans += n;
        cout << max(ans-1, 1) << endl;
    }
    return 0;
}