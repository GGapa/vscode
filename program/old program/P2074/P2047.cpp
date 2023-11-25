//P2074 危险区域
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
double add(int x1,int y1,int x2,int y2)
{
    return double(sqrt(pow(x1-x2,2)+pow(y1-y2,2)));
}
int main()
{
    int n,m,k,t;int maxn=0;
    scanf("%d%d%d%d",&n,&m,&k,&t);
    while(k--)
    {
        int x;int y;int ans=0;
        scanf("%d%d",&x,&y);
        for(int i = max(1,x-t);i<=min(n,x+t);i++)
        {
            for(int j = max(1,y-t);j<=min(m,y+t);j++)
            {
                if(add(x,y,i,j)<=double(t))
                {
                    ans++;
                }
            }
        }
        maxn=max(maxn,ans);
    }
    cout<<maxn<<endl;
    return 0;
}