#include <iostream>
#include <cstdio>
#include <vector>
#include <limits.h>
using namespace std;

const long long maxn=10e5+5;
struct Node
{
    long long next;
    long long weight;
};

vector <Node> node[maxn];//下一个 权重
long long ans[maxn][3];  //最短路径  是否标记
long long n,m,s;
int main()
{
    scanf("%d%d%d",&n,&m,&s);
    for(long long i = 1;i<=m;i++)
    {
        long long t1,t2,t3;
        cin>>t1>>t2>>t3;
        node[t1].push_back({t2,t3});
        ans[i][1]=LONG_LONG_MAX;
    }
    ans[s][1]=0;
    while(true)
    {
        bool brek=true;
        /*
        for(long long i = 1;i<=n;i++)
        {
            if(ans[i][2]==0){brek=false;break;}
        }
        */
        long long smallit,smallnum=LLONG_MAX-1;
        for(long long i = 1;i<=n;i++)
        {
            if(smallnum>=ans[i][1]&&ans[i][2]==0&&ans[i][1]!=LONG_LONG_MAX)
            {
                smallnum=ans[i][1];
                smallit=i;
                brek=false;
            }
        }
        if(brek)break;
        ans[smallit][2]=1;
        for(long long i = 0;i<node[smallit].size();i++)
        {
            if(ans[node[smallit][i].next][1]>ans[smallit][1]+node[smallit][i].weight)ans[node[smallit][i].next][1]=ans[smallit][1]+node[smallit][i].weight;
        }
    }
    for(long long i = 1;i<=n;i++)
    {
        if(ans[i][1]!=LONG_LONG_MAX)printf("%lld ",ans[i][1]);
        else printf("%d ",2147483647);
    }
    return 0;
}
