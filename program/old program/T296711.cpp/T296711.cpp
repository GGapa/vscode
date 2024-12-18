//T296711 「UOI-R1」询问
#include <iostream>
#include <cstdio>
using namespace std;
int num[1000005];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&num[i]);
    }
    while(m--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        num[x]-=y;
    }
    for(int i = 1;i<=n;i++)
    {
        printf("%d ",num[i]);
    }
    return 0;
}