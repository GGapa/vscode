//P7018 [CERC2013] Bus

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&k);
        long long ans=1;
        for(int i = 1;i<k;i++)
        {
            ans=ans*2+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}