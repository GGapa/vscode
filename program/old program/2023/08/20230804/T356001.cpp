//T356001 异或 (xor)
//https://www.luogu.com.cn/problem/T356001?contestId=119800
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long
#define int long long
const int maxn = 10e5;

inline int read()
{
    int f = 1, x = 0;
    char c;
    c = getchar();
    while(!isdigit(c))
    {
        if(c == '-') f = -1;
        c = getchar();
    }
    while(isdigit(c))
    {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x;
}
int a[maxn], b[maxn], c[maxn], n, ans[maxn];
bool abmin2 = true;
int a1 = 0, b1 = 0;
signed main()
{
    //freopen("xor.in", "r", stdin);
    //freopen("xor.out", "w", stdout);
    n = read();
    for(int i = 1; i <= n; i++)
    {
        a[i] = read();
        if(a[i] >= 2)abmin2 = false;
        if(a[i] == 1)a1++;
    }
    for(int i = 1; i <= n; i++)
    {
        b[i] = read();
        if(a[i] >= 2)abmin2 = false;
        if(b[i] == 1)b1++;
    }
    if(abmin2)
    {
        int tmp = abs(a1 - b1);
        for(int i = 1;i <= n - tmp; i++)
        {
            printf("0 ");
        }
        for(int i = 1; i <= tmp; i++)
        {
            printf("1 ");
        }
        cout << '\n';
    }
    if(n <= 6)
    {
        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + n);
        memset(ans, 20, sizeof(ans));
        while(next_permutation(a + 1, a + 1 + n))
        {
            while(next_permutation(b + 1, b + 1 + n))
            {
                for(int i = 1; i <= n; i++)
                {
                    c[i] = a[i] ^ b[i];
                }
                sort(c + 1, c + 1 + n);
                for(int i = 1; i <= n; i++)
                {
                    if(c[i] < ans[i])
                    {
                        for(int i = 1; i <= n; i++)
                        {
                            ans[i] = c[i];
                        } 
                        break;
                    }
                    else if (c[i] != ans[i])
                    {
                        break;
                    }
                }

            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}