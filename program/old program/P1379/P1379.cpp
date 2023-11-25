// P1379 八数码难题
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
#define ll long long
const long long STD = 123804765;
using namespace std;
queue<ll> Q;
map<ll, ll> mp;
int fx[4] = {-1, 1, 0, 0}, fy[4] = {0, 0, -1, 1}; // 方向数组上下左右
int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    Q.push(n);
    mp[n] = 0;
    while (!Q.empty())
    {
        ll t = Q.front();
        Q.pop();
        int Map[4][4];
        if (t == STD)
            break;
        int sx, sy;
        int T = t;
        for (int i = 3; i >= 1; i--)
        {
            for (int j = 3; j >= 1; j--)
            {
                Map[i][j] = t % 10;
                t /= 10;
                if (Map[i][j] == 0)
                    sx = i, sy = j;
            }
        }
        for (int i = 0; i <= 3; i++)
        {
            int nx = sx + fx[i];
            int ny = sy + fy[i];
            if (nx < 1 || ny<1 | nx> 3 || ny > 3)
                continue;
            swap(Map[nx][ny], Map[sx][sy]);
            ll tmp = 0;
            for (int j = 1; j <= 3; j++)
            {
                for (int k = 1; k <= 3; k++)
                {
                    tmp = tmp*10 + Map[j][k];
                }
            }
            if (mp.count(tmp) == 0)
            {
                mp[tmp] = mp[T];
                mp[tmp]++;
                Q.push(tmp);
            }
            swap(Map[nx][ny], Map[sx][sy]);
        }
    }
    cout << mp[STD] << "\n";
    return 0;
}