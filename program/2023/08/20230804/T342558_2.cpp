#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
int T, n, a[maxn], sum[maxn][105];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--)
    {
        cin >> n;
        memset(sum, 0, sizeof(sum));
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum[i][a[i]]++;
            for(int j = 0; j <= 100; j++)
            {
                sum[i][j] += sum[i-1][j];
            }
        }
        int mid = n / 2;
        if(n % 2 == 0)
        {
            bool flag = true;
            for(int i = 0; i <= 100; i++)
            {
                if(sum[n][i] - sum[mid][i] != sum[mid][i])
                {
                    flag = false;
                    cout << "YES" << endl;
                    break;
                }
            }
            if(flag) cout << "NO" << endl;
        }
    }
    
}