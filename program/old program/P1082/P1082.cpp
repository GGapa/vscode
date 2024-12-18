//P1082 [NOIP2012 提高组] 同余方程
#include <iostream>
#include <cstdio>
using namespace std;
long long x;long long y;
void exgcd(long long a,long long b)
{
    if (b==0)
    {
        x=1;
        return ;
    }
    exgcd(b,a%b);
    long long k = x;
    x=y;
    y=k-a/b*y;
}
int main()
{
    long long a,b;
    cin>>a>>b;
    exgcd(a,b);
    x=(x%b+b)%b;
    cout<<x<<endl;
    return 0;
}