#include <iostream>
#include <algorithm>
using namespace std;
struct ro
{
    int l,r;
}road[10001];
bool cmp(ro x,ro y)
{
    return x.l<y.r;
}
int main()
{
    int n,l,len=-1,ans=0;
    cin>>n>>l;
    for(int i= 0;i<n;i++)
    {   
        int x,y;
        cin>>road[i].l>>road[i].r;
    }
    sort(road,road+n,cmp);
    int now=0;
    now=road[0].l;
    for(int i = 0;i<n;i++)
    {
        now=max(now,road[i].l);
        while(now<road[i].r)
        {
            now+=l;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}