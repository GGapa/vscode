#include <iostream>
#include <cstdio>
using namespace std;
long long n,k;
long long ans=0,add=1,now;
void init()
{
    scanf("%d %d",&n,&k);
}
int main()
{
    freopen("shuiguo.in","r",stdin);
    freopen("shuiguo.out","w",stdout);
    init();
    while(n>0)
    {
        now=(n-(n/2))/k;
        now+=(n-(n/2))%k==0?0:1;
        ans+=now*add;
        n-=now*k;
        add*=2;
    }
    cout<<ans<<endl;
    return 0;
}
