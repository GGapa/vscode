#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
#define int long long
const int maxn = 45;
const int msum = 1 << 21;
int n, m;
ll a[maxn], suma[msum], sumb[msum];
ll indexa,indexb;
void dfs(int l, int r, ll sum, ll A[], ll &index)
{
    if(sum>m)return;
    if(l>r)
    {
        A[++index]=sum;
        return;
    }
    dfs(l+1,r,sum+a[l],A,index);
    dfs(l+1,r,sum,A,index);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)cin>>a[i];
    int mid = n >> 1;
    dfs(1, mid, 0, suma, indexa);
    dfs(mid + 1, n, 0, sumb, indexb);
    ll ans = 0;
    sort(suma + 1, suma + 1 + indexa);
    for(int i = 1; i <= indexb; i++)
        ans += upper_bound(suma + 1, suma + 1 + indexa, m - sumb[i]) - suma - 1;
    cout << ans << endl;
    return 0;
}