// P2040 打开所有的灯
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <random>
#include <randint>
#include <>
using namespace std;
const int maxn = 5;
int map[maxn][maxn];
int fx[5] = {0, 0, 1, -1, 0}, fy[5] = {1, -1, 0, 0, 0}, ans = 100;
bool used[maxn][maxn] = {false};
bool cheak()
{
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            if (!map[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
void change(int x, int y)
{
    for (int i = 0; i < 5; i++)
    {
        map[x + fx[i]][y + fy[i]] = 1 - map[x + fx[i]][y + fy[i]];
    }
}
void dfs(int step)
{
    if (step >= ans)
        return;
    if (cheak())
        ans = min(ans, step);
    else
    {
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                if (!used[i][j])
                {
                    used[i][j] = 1;
                    change(i, j);
                    dfs(step + 1);
                    used[i][j] = 0;
                    change(i, j);
                }
            }
        }
    }
}
int main()
{
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    dfs(0);
    cout << ans << endl;
    return 0;
}