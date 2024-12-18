// 动态规划DP
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 5e6 + 5;
int n;
struct Couple
{
    int index, impact, left, right;
};
Couple couple[maxn];
int map[maxn];
bool used[maxn];
bool cmp(Couple x,Couple y)
{
    return x.impact>y.impact;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> couple[i].impact;
        couple[i].left = max(1, i - couple[i].impact);
        couple[i].right = min(n, i + couple[i].impact);
    }
    sort(couple+1,couple+1+n,cmp);
    for (int i = couple[1].left; i <= couple[1].right; i++)
        map[i] = 1;
    used[1] = true;
    int ans = 1;
    for (int i = 2; i <= n; i++)
    {
        if (map[i] != 0)
        {
            int tmp = 0;
            for (int j = i - 1; j >= 1; j--)
            {
                if (couple[j].left >= couple[i].left && couple[j].right <= couple[i].right&&used[j])
                {
                    used[j]=false;
                    tmp++;
                }
            }
            if (tmp != 0)
            {
                ans -= tmp;
                ans++;
                for (int j = couple[i].left; j <= couple[i].right; j++)
                {
                    map[j] = i;
                }
                used[i]=true;
            }
        }
        if (map[i] == 0)
        {
            used[i]=true;
            ans++;
            for (int j = couple[i].left; j <= couple[i].right; j++)
            {
                map[j] = i;
            }
        }
    }
    cout << ans << endl;
    return 0;
}