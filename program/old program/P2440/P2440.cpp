#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n,k;
int a[100000001];
int main()
{
    long long l=0,r=100000001,mid;
    scanf("%d%d",&n,&k);
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    while(r-l>1)
    {
        mid=(l+r)/2;
        bool bj;
        int sum=0;
        for(int i = 1;i<=n;i++)
        {
            sum+=a[i]/mid;
        }
        if(sum<k)r=mid;
        else l=mid;
        //cout<<mid<<endl;
    }
    cout<<l<<endl;
    return 0;

}