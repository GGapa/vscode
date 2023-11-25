//P1158 [NOIP2010 普及组] 导弹拦截
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;



int x1,x2,yy,y2;
int n;
int mins1=0,mins2=0;

struct A
{
    int s1,s2;
};
A missile[100005];
bool cmp(A x ,A y)
{
    return x.s1<y.s1;
}
int main()
{
    scanf("%d%d%d%d",&x1,&yy,&x2,&y2);
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        int tmpx,tmpy;
        scanf("%d%d",&tmpx,&tmpy);
        missile[i].s1=pow(x1-tmpx,2)+pow(yy-tmpy,2);
        missile[i].s2=pow(x2-tmpx,2)+pow(y2-tmpy,2);
    }
    sort(missile+1,missile+1+n,cmp);
    int ans=missile[n].s1,hei=-1;
    for(int i = n-1;i>=1;i--)
    {
        hei=max(hei,missile[i+1].s2);
        ans=min(ans,hei+missile[i].s1);
    }
    cout<<ans<<endl;
    return 0;
}
