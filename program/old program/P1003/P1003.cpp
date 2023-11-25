//P1003 [NOIP2011 提高组] 铺地毯
#include <iostream> 
#include <map>
#include <cstdio>
using namespace std;
const int maxn = 1e4+10;
int a[maxn],b[maxn],c[maxn],d[maxn],x,y,ans=0;
int n;

int main()
{
	scanf("%d",&n);
	for(int i = 1;i<=n;i++)
	{
		scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
	}
	scanf("%d %d",&x,&y);
	for(int i = 1;i<=n;i++)
	{
		if(a[i]<=x&&b[i]<=y&&x<=a[i]+c[i]&&y<=b[i]+d[i])ans=i;
	}
	if(ans!=0)cout<<ans<<endl;
	else cout<<-1<<endl;
	return 0;
}
