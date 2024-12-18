//P2397 yyy loves Maths VI (mode)
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    long long maxlen=-1,maxnum,n,last=0,len=1;
    scanf("%lld",&n);
    for(int i = 1;i<=n;i++)   
    {
        long long in;
        scanf("%lld",&in);
        if(i==1)last=in;
        if((last!=in&&i!=0)||i==n)
        {
            if(len>maxlen)
            {
                maxnum=last;
                maxlen=len;
                len=1;
            }
        }
        else
        {
            len++;
        }
        last=in;
    }
    cout<<maxnum<<endl;
    return 0;
}