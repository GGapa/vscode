//P6284 [COCI2016-2017#1] Tarifa
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int x,n,ans=0;
    cin>>x>>n;
    for(int i = 1;i<=n;i++)
    {
        int input;
        cin>>input;
        ans+=x-input;
    }
    cout<<ans+x<<endl;
    return 0;
}