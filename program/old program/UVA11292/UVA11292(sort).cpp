//UVA11292 Dragon of Loowater
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define lose 
bool cmp(int x,int  y)
{
    return x<y;
}
int main()
{
    int people[20005],dragon[20005];
    int n,m;//n龙  m骑士

    while(true)
    {
        int sum=0,successkilled=0;
        scanf("%d %d",&n,&m);
        if(n+m==0)return 0;
        memset(people,0,sizeof(people));
        memset(dragon,0,sizeof(dragon));
        for(int i = 1;i<=n;i++)
        {
            scanf("%d",&dragon[i]);
        }
        for(int i = 1;i<=m;i++)
        {
            scanf("%d",&people[i]);
        }
        if(n>m)
        {
            printf("Loowater is doomed!\n");
            continue;
        }
        sort(dragon+1,dragon+1+n,cmp);
        sort(people+1,people+m+1,cmp);
        int l=1;
        for(int i = 1;i<=m;i++)
        {
            if(people[i]>=dragon[l])
            {
                l++;
                successkilled++;
                sum+=people[i];
                if(l==n+1)break;
            }
        }
        if(successkilled<n)
        {
            printf("Loowater is doomed!\n");
        }
        else
        {  
            printf("%d\n",sum);
        }
    }
    return 0;
}