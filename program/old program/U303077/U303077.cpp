#include <iostream>
#include <cstring>
#include <vector>
#include <limits.h>
#include <cstdio>
using namespace std;
#define mod 988244353
int t[1000005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> a;
    int ans=0;
    for(int i = 1;i<=n;i++)
    {
        int tmp;
        cin>>tmp;
        for(int j = 1;j<=tmp;j++)
        {
            a.push_back(j);
        }
    }
    for(int i = 0;i<a.size();i++)
    {
        for(int j = 0;j+i<a.size();j++)
        {
            int Min=INT_MAX,Maxnum=-1,MMax=-1;
            memset(t,0,sizeof(t));
            for(int q = j;q<=j+i;q++)
            {
                t[a[q]]++;
                MMax=max(MMax,a[q]);
            }
            for(int q = 0;q<=MMax;q++)
            {
                if(Maxnum<t[q]&&t[q]!=0)
                {
                    Min=q;
                    Maxnum=t[q];
                }
            }
            ans+=Min;
            ans%=mod;
        }
    }
    cout<<ans<<endl;
}