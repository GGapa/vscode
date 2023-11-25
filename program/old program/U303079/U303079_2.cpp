//40 score
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define maxn 1000005
#define int long long
//priority_queue<int>que;
int n,k;
long long a[maxn],b[maxn];
long long Max=-1,ans=0;
int it;
long long cnt=0,cntt=0;
signed main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin>>n>>k;
    
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
        b[a[i]]++;
        Max=max(Max,b[a[i]]);
    }
    /*
    if(k>=Max)
    {
        cout<<"pigstd"<<endl;
        return 0;
    }
    */
    sort(b+1,b+n+1);
    it=n+1;
    while(b[it-1]==Max)
        it--,ans++,cnt+=b[it],cntt++;
    it-=1;
    for(int i = it;i>=1;i--)
    {
        if(b[i]==0)break;
        int ave;
        cnt+=b[i];
        cntt++;
        if(cnt%cntt!=0)ave=cnt/cntt+1;
        else ave=cnt/cntt;
        int tmp=ave-b[i];
        if(tmp<=k)
        {
            k-=tmp;
            ans++;
        }
    }
    if(k>=cnt/cntt)cout<<"pigstd"<<endl;
    else cout<<ans<<endl;
    return 0;


}