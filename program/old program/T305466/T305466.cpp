//T305466 『GROI-R1』 虹色的彼岸花
#include <iostream>
#include <cstdio>
using namespace std;
const int Mod = 1e9+7;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,l,r;
        cin>>n>>l>>r;
        long long ls=1;
        for(int i = 1;i<=n;i++)
        {
            ls*=(r-l+1);
            ls%=Mod;
        }
        cout<<ls<<endl;
    }
    return 0;
}