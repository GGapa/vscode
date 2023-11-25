//P1644 跳马问题
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n, m, ans = 0;
void dfs(int x, int y)
{
    if (x > n || x < 0 || y > m)
        return;
    if (x == n && y == m)
        ans++;
    else
    {
        dfs(x + 2, y + 1);
        dfs(x + 1, y + 2);
        dfs(x - 1, y + 2);
        dfs(x - 2, y + 1);
    }
}
int main()
{
    cin >> n >> m;
    dfs(0,0);
    cout << ans << endl;
    return 0;
}