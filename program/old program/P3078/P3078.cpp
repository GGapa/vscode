#include <iostream>
#include <cstdio>
using namespace std;
long long n,a[1000005],ans;
int main()
{
    scanf("%lld",&n);
    for(int i = 1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i = 2;i<=n;i++)
    {
        if(a[i]>a[i-1])ans+=a[i]-a[i-1];
    }
    cout<<ans+a[1]<<endl;
    return 0;
}