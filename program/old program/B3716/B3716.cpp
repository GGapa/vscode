// B3716 分解质因子 3
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e8;
int number[maxn + 10], prime[5770000];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int index = 0;
    for (int i = 2; i <= 100000000; i++)
    {
        if (!number[i])
            prime[++index] = i;
        for (int j = 1; j <= index && (long long)prime[j] * i <= 100000000; j++)
        {
            number[prime[j] * i] = prime[j];
            if (!(i % prime[j]))
                break;
        }
    }
    int T;
    cin >> T;
    while (T--)
    {
        int ans = 0;
        int n;
        cin >> n;
        if (number[n] == 0)
        {
            cout << n << endl;
            continue;
        }
        while (true)
        {
            if (!number[n])
            {
                ans ^= n;
                break;
            }
            ans ^= number[n];
            n /= number[n];
        }
        cout << ans << '\n';
    }
    return 0;
}