//P1865 A % B Problem
#include <iostream>
#include <cstdio>
using namespace std;
int a[1000005],b[1000005];
void init(int r)
{
    for(int i = 2;i<=r-1;i++)
    {
        for(int j = i*2;j<=r;j+=i)
        {
            b[j]=1;
        }
    }
    for(int i = 2;i<=r;i++)
    {
        a[i]+=a[i-1];
        a[i]+=(1-b[i]);
    }
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    init(m);
    
    for(int i = 1;i<=n;i++)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        if(l<1||r>m)
        {
            printf("Crossing the line\n");
        }
        else
        {
            printf("%d\n",a[r]-a[l-1]);
        }
    }
    return 0;
}