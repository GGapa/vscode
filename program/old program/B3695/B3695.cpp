#include <iostream>
#include <cstdio>
#include <cstring>
#include <bitset>   
using namespace std;
bitset<60005> a[30005],mmax,ans;
int n,m,q;
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i = 1;i<=m;i++)mmax[i]=1;
    for(int i = 1;i<=n;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        for(int j= 1;j<=tmp;j++)
        {
            int tmp1;
            scanf("%d",&tmp1);
           //cout<<a[j]<<endl;
            a[i][tmp1]=1;
        }
    }
    for(int i = 1;i<=q;i++)
    {
        int o,x,y;
        scanf("%d%d%d",&o,&x,&y);
        if(o==1)a[x]=(a[x]<<y)&mmax;
        if(o==2)a[x]=(a[x]>>y)&mmax;
        if(o==3)ans=a[x]&a[y];
        if(o==4)ans=a[x]|a[y];
        if(o==5)ans=a[x]^a[y];
        if(3<=o&&o<=5)printf("%d\n",ans.count());
    }
    return 0;
}