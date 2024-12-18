//  Longest Divisors Interval
// https://codeforces.com/contest/1855/problem/B
// https://codeforces.com/contest/1855/problem/B
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define ll long long
#define int long long
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        ll n,ans=0;
        cin>>n;
        for(ll i = 1;i<=n;i++)
        {
            if(n%i==0)
            {
                ans++;
            }
            else break;
        }
        cout<<ans<<endl;
    }
}