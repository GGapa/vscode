//U303079 众数 I
//https://www.luogu.com.cn/contest/38434

//20 score
#include <iostream>
#include <cstdio>
using namespace std;
#define maxn 1000005
#define mod 998244353
int a[maxn],b[maxn];
int n,k,Max,ans=0;

namespace A  //k==0
{
    void main()
    {
        for(int i = 1;i<=n;i++)
        {
            if(b[i]==Max)ans++;
        }
        cout<<ans<<endl;
        exit(0);
    }
}

namespace B //k==1
{
    void main()
    {
        for(int i = 1;i<=n;i++)
        {
            //if(k==0)break;
            if(b[i]==Max)ans++;
            else if((b[i]+k>=Max||(b[i]!=0&&b[i]+k>=Max-k))&&b[i]<Max&&k!=0)
            {
                ans++;
                k--;
            }
        }
        cout<<ans<<endl;
        exit(0);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
        b[a[i]]++;
        Max=max(Max,b[a[i]]);
    }
    if(k==0)A::main();
    if(k==Max)
    {
        cout<<"pigstd"<<endl;
        exit(0);
    }
    if(k==1)
    {
        B::main();
    }
    return 0;
}