#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define maxn 100005
int protect[maxn],attack[maxn],ans=0;
bool used[maxn];
int main()
{
    int m,n,nowp;
    scanf("%d%d",&m,&n);
    nowp=1;
    for(int i = 1;i<=m;i++)
    {
        scanf("%d",&protect[i]);
    }
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&attack[i]);
    }
    sort(protect+1,protect+1+m);
    sort(attack+1,attack+1+n);
    while(protect[nowp]==0)nowp++;
    for(int i = 1;i<=n;i++)
    {
        if(attack[i]>protect[nowp]&&protect[nowp]!=0)
        {
            used[i]=1;
            nowp++;
        }
    }
    if(nowp<=m||nowp==1)
    {
        cout<<0<<endl;
        return 0;
    }
    for(int i = 1;i<=n;i++)
    {
        if(!used[i])ans+=attack[i];
    }
    cout<<ans<<endl;
    return 0;
}