#include <iostream>
#include <cstdio>
#include <limits.h>
using namespace std;
const int maxn = 5e6+5;
int n;
inline int read()
{
    int x=0,f=1;
    char c;
    c=getchar();
    while(!isdigit(c))
    {
        if(c=='-')f=-1;
        c=getchar();
    }
    while(isdigit(c))
    {
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    }
    return x*f;
}
bool map[maxn];
struct Couple
{
    int impact, left, right;
};
Couple couple[maxn];
bool bj[maxn],a[maxn];
void dfs(int x,int num)
{
    bool flag=true;
    for(int i = 1;i<=n;i++)
    {
        if(!bj[i])
        {
            flag=false;
            break;
        }
    }
    if(flag)
    {
        ans=min(ans,num);
        return ;
    }
    if(x>n)return ;
    for(int )

}
int main()
{
    n=read();
    for(int i = 1;i<=n;i++)
    {
        couple[i].impact=read();
        couple[i].left=max(1,i-couple[i].impact);
        couple[i].right=min(n,couple[i].impact+i);
    }
    dfs(1,1);
}