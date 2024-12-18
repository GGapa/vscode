//T342558 「SFCOI-3」进行一个走的行
//https://www.luogu.com.cn/problem/T342558?contestId=118761
// 10pts
#include <iostream>
#include <cstdio>
using namespace std;

const int maxn  = 2e5 + 5;
int n,m;
struct A
{
    int l,r,v;
};
A a[maxn];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].l >> a[i].r >> a[i].v;
    }
    for(int i = 1, l, r, x; i <= m; i++)
    {
        cin >> l >> r >> x;
        long long ans = 0;
        for(int j = l; j <= r; j++)
        {
            if(a[j].r != -1 && a[j].l <= x && a[j].r >= x) ans += a[j].v;
            if(a[j].r == -1 && x - a[j].l > 0) ans += a[j].v, x -= a[j].l;
        }
        cout << ans << endl;
    }
    return 0;
}

