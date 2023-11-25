#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define maxn 20005
int l[maxn],r[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        cin>>l[i]>>r[i];
    }
    sort(l+1,l+1+n);
    sort(r+1,r+1+n);
    long long ans=0;
    ans+=r[1]-l[1];
    for(int i = 2;i<=n;i++)
    {
        if(l[i]<=r[i-1])ans+=r[i]-r[i-1];
        else ans+=r[i]-l[i];
    }
    cout<<ans<<endl;
    return 0;
}