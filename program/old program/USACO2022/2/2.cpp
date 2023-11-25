// 喂奶牛
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int n, k, map[2][100005];
        char ans[100005];
        memset(map, 0, sizeof(map));
        memset(ans, '.', sizeof(ans));
        string a;
        scanf("%d%d", &n, &k);
        getline(a);
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 'G')
            {
                for (int j = i; abs(j - i) <= k, j > -1, j < n; j--)
                    map[0][j]++;
                for (int j = i + 1; abs(j - i) <= k, j > -1, j < n; j++)
                    map[0][j]++;
            }
            if (a[i] == 'H')
            {
                for (int j = i; abs(j - i) <= k, j > -1, j < n; j--)
                    map[1][j]++;
                for (int j = i + 1; abs(j - i) <= k, j > -1, j < n; j++)
                    map[1][j]++;
            }
        }
        for (int i = 0; i < n; i++)
        {

            if (ans[i] == '.')
            {
                ans[i] = 'G';
                for (int j = i; abs(j - i) <= k, j > -1, j < n; j--)
                    map[0][j] = 0;
                for (int j = i + 1; abs(j - i) <= k, j > -1, j < n; j++)
                    map[0][j] = 0;
            }
        }
    }
}