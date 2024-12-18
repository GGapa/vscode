//P2249 【深基13.例1】查找
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[1000005],n,m,x;
int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i = 1;i<=m;i++)
    {
        scanf("%d",&x);
        int ans=lower_bound(a+1,a+1+n,x)-a;
        if(a[ans]!=x)cout<<-1<<" ";
        else cout<<ans<<" ";
    }
    cout<<endl;
    return 0;
}