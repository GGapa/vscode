// P3368 【模板】树状数组 2
#include <iostream>
#include <cstdint>
using namespace std;
const int maxn = 5e5 + 5;
int n, m, a[maxn], c[maxn];
int lowbit(int x)
{
    return x & -x;
}
void add(int x, int y)
{
    while (x <= n)
    {
        c[x] += y;
        x += lowbit(x);
    }
}

int ask(int x)
{
    int y = 0;
    while (x != 0)
    {
        y += c[x];
        x -= lowbit(x);
    }
    return y;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        add(i, a[i] - a[i - 1]);
    }
    for (int i = 1; i <= m; i++)
    {
        int op, x, y, k;
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y >> k;
            add(x, k);
            add(y+1,-k);
        }
        else
        {
            cin>>x;
            cout << ask(x) << endl;
        }
    }
    return 0;
}