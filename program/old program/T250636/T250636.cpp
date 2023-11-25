//T250636 [JRKSJ R5] 1-1 A
//Good Luck =)
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n,a[1000005],fu=0,zhen=0;
int main()
{
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<=0)fu++;
        if(a[i]>0)zhen++;
    }
    sort(a+1,a+1+n);
    int z=zhen/fu;
    return 0;
}