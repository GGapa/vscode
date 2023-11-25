#include <iostream>
#include <cstdio>
#include <vector>
#define ull unsigned long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int m, n;
        cin>>n>>m;
        vector< ull > a(n), b(m);
        /*
        for (int i = 1; i <= n; i++)
        {
            ull tmp;
            cin>>tmp;
            a.push_back(tmp);
        }
        */
       for(auto &i:a) cin>>i;
       for(auto &i:b) cin>>i;
       /*
        for(int i = 1;i<=m;i++)
        {
            ull tmp;
            cin>>tmp;
            b.push_back(tmp);
        }
        */
        int ita=0,itb=0;
        int ans=0;
        while(ita<n)
        {
            int count=0;
            while(itb<m&&b[itb]<=a[ita])
            {
                if(b[itb]==a[ita])count++;
                itb++;
            }

            ita++;
            if(ans==0)ans=count;
            else ans^=count;
        }
        cout<<ans<<endl;
    }
    
}