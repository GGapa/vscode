//P2311 loidc，想想看
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
    int n,a[100005];
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    int m;
    scanf("%d",&m);
    for(int i = 1;i<=m;i++)
    {
        int l,r;
        pair <int,int> p(-1,-1);
        scanf("%d %d",&l,&r);
        for(int j = l;j<=r;j++)
        {
            if(a[j]>p.first)
            {
                p.first=a[j];
                p.second=j;
            }
        }
        cout<<p.second<<endl;
    }
    return 0;
}