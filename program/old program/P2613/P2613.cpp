//P2613 【模板】有理数取余
#include <iostream>
#include <cstdio>

using namespace std;
#define mod 19260817
long long x;long long y;.
inline int read()
{
    int res = 0, ch = getchar();
    while(!isdigit(ch) && ch != EOF)
        ch = getchar();
    while(isdigit(ch))
    {
        res = (res << 3) + (res << 1) + (ch - '0');
        res %= mod;
        ch = getchar();
    }
    return res;
}
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
    a=read();
    b=read();
    a%=mod;
    b%=mod;
    if(b == 0)
    {
        printf("Angry!");
        return 0;
    }
    exgcd(b,mod);
    x=(x%mod+mod)%mod;
    cout<<a*x%mod<<endl;
    return 0;
}