// P2327 [SCOI2005]扫雷
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define maxn 10004
int map[maxn], boob[maxn], now[maxn], ans = 2;
int n;
void ch()
{
    for (int i = 2; i <= n+1; i++)
    {
        boob[i] = map[i - 1] - boob[i - 1] - boob[i - 2];
        if (boob[i] != 0 && boob[i] != 1)
        {
            ans--;
            break;
        }
        if (boob[i] == 1)
        {
            now[i - 1]++;
            now[i]++;
            now[i + 1]++;
            if (i == n && (now[i - 1] != map[i - 1] || map[i] != now[i] || map[i - 2] != map[i - 2]))
            {
                ans--;
                break;
            }
            else if (now[i - 1] != map[i - 1])
            {
                ans--;
                break;
            }
        }
        if(i==n+1&&boob[i]!=0)
        {
            ans--;
            break;
        }
    }
}
int main()
{
    scanf("%d", &n);
    memset(boob, 0, sizeof(boob));
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &map[i]);
    }
    boob[1] = 1;
    now[1]++;
    now[2]++;
    if (map[1] >= 3 || map[n] >= 3)
    {
        cout << 0 << endl;
        return 0;
    }
    ch();
    memset(now, 0, sizeof(now));
    boob[1] = 0;
    ch();
    cout << ans << endl;
    return 0;
}