// P1057 [NOIP2008 普及组] 传球游戏
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, location[32], ans = 0;
void dg(int num, int it)
{
    if (num > m)
        return;
    if (num == m && it == 1)
    {
        ans++;
        return;
    }
    if(it==1)
    {
        dg(num+1,n);
        dg(num+1,2);
    }
    else if(it==m)
    {
        dg(num+1,m-1);
        dg(num+1,1);
    }
    else
    {
        dg(num+1,it-1);
        dg(num+1,it+1);
    }
    
}
int main()
{
    scanf("%d%d", &n, &m);
    dg(0, 1);
    cout<<ans<<endl;
    return 0;
}


//0 score