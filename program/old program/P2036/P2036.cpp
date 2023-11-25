//P2036 [COCI2008-2009#2] PERKET
#include <iostream>
#include <cstdio>
#include <queue>
#include <limits.h>
using namespace std;
int s[11],b[11],n,ans=INT_MAX;
inline void dfs(int x,int y,int z)
{
    if(x>n)
    {
        if(y==1&&z==0)return ;
        else ans=min(abs(y-z),ans);
        return ;
    }
    dfs(x+1,y,z);
    dfs(x+1,y*s[x],z+b[x]);
}
int main()
{
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)scanf("%d %d",&s[i],&b[i]);
    dfs(1,1,0);
    printf("%d",ans);
}