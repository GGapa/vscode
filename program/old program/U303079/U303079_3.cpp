
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
#define maxn 10000005
#define int long long
priority_queue <int >a,b;
int A[maxn],B[maxn];
int n,k;
int Max,Maxnum;
long long sum;
int ans=0;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i = 1;i<=n;i++)
    {
        int tmp;
        cin>>A[i];
        B[A[i]]++;
    }
    int cnt=0;
    for(int i = 1;i<=n;i++)
    {
        if(B[i]!=0)
        {
            cnt++;
        }
    }
    int avr;
    if(n%cnt==0)avr=n/cnt;
    else avr=n/cnt+1;
    int ans=0;
    for(int i = 1;i<=n;i++)
    {
        if(avr-B[i]<=k&&B[i]!=0)ans++;
    }
    cout<<ans<<endl;
    return 0;
}