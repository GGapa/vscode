// https://www.luogu.com.cn/problem/B3716
// https://www.luogu.com.cn/problem/B3716
// B3716 分解质因子 3
#include <iostream>
#include <bitset>
using namespace std;
const int maxn = 1e8 + 5;
bitset<maxn> vis;
int n, T, p[maxn / 10], Min[maxn];
void GetPrime()
{
    for (int i = 2; i <= maxn; i++)
    {
        if (!vis[i])
        {
            p[++p[0]] = i;
            Min[i] = i;
        }
        for (int j = 1; j <= p[0] && 1ll * i * p[j] < maxn; j++)
        {
            vis[i * p[j]] = 1;
            Min[i * p[j]] = p[j];
            if (i % p[j] == 0)
                break;
        }
    }
}
int main()
{
    GetPrime();
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        int x;
        cin >> x;
        int ans = 0;
        while(x > 1) 
        {
            ans ^= Min[x];
            x /= Min[x];
        }
        cout << ans << endl;
    }
    return 0;
}