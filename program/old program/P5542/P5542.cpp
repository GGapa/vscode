// P5542 [USACO19FEB] Painting The Barn S
#include <iostream>
using namespace std;
#define maxn 1005
int map[maxn][maxn], f[maxn][maxn];
int n, k;
int ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    while (n--)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        map[x1+1][y1 + 1]++;
        map[x2+1][y2 + 1]++;
        map[x1 + 1][y2 + 1]--;
        map[x2 + 1][y1 + 1]--;
    }
    for (int i = 1; i <= maxn - 5; i++)
    {
        for (int j = 1; j <= maxn - 5; j++)
        {
            map[i][j] += map[i - 1][j] + map[i][j - 1] - map[i - 1][j - 1];
            if (map[i][j] == k)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}