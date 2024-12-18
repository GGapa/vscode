#include <iostream>
#include <cmath>
using namespace std;
#define maxn 100005
int a[25][maxn];
int n, m;

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    n = read();
    m = read();
    for (int i = 1; i <= n; i++)
        a[0][i] = read();
    for (int i = 1; i < 20; i++)
    {
        for (int j = 1; j + (1 << i) - 1 <= n; j++)
        {
            a[i][j] = max(a[i - 1][j], a[i - 1][j + (1 << (i - 1))]);
        }
    }
    while (m--)
    {
        int l = read();
        int r = read();
        int tlen = log2(r - l + 1);
        cout << max(a[tlen][l], a[tlen][r - (1 << tlen) + 1]) << "\n";
    }
    return 0;
}
