//T250634 『JROI-7』PMK 配匹串符字
#include <iostream>
#include <cstdio>
using namespace std;
int n;
int main()
{
    scanf("%d",&n);
    for(int i = 0;i<min(n,26);i++)
    {
        cout<<char(i+'a');
    }
    n-=26;
    if(n>0)
    {
        for(int i = 1;i<=n;i++)
        {
            putchar('z');
        }
    }
    return 0;
}