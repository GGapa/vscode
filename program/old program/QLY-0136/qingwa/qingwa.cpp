#include <iostream>
#include <cstdio>
using namespace std;
#define maxn 100005
long long kkk[maxn]={0},ans=0;
int n,k,a[maxn];
void init()
{   
    scanf("%d %d",&n,&k);
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        kkk[i]=kkk[i-1]+a[i];
    }

}
int main()
{
    freopen("qingwa.in","r",stdin);
    freopen("qingwa.out","w",stdout);
    init();
    for(int i = 1;i<=n;i++)
    {
        if(kkk[i]%k==0)ans++;
        for(int j = i-1;j>0;j--)
        {
            if((kkk[i]-kkk[j])%k==0)ans++;
        }
    }
    printf("%d",ans);
    return 0;
}