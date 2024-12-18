//T309754 [yLOI2022] 枕万梦
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
#define maxn 1000005
struct Number
{
    int value,it;
};
Number a[maxn];
bool cmp(Number x,Number y)
{
    if(x.value!=y.value)return x.value<y.value;
    return x.it<y.it;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i].value;
        a[i].it=i;
    }
    sort(a+1,a+1+n,cmp);
    for(int i = 1;i<=n;i++)
    {
        cout<<a[i].it<<" ";
    }
    cout<<'\n';
    return 0;
}
