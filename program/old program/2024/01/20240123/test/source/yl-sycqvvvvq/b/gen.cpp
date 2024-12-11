#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("b.in","w",stdout);
    int n1=800,n2=800,q=100;
    // sran
    cout<<n1<<" "<<n2<<'\n';
    for(int i=2;i<=n1;i++)
        cout<<i-1<<' ';
    cout<<'\n';
    for(int i=2;i<=n2;i++)
        cout<<i-1<<' ';
    cout<<'\n';
    cout<<1<<'\n';
    for(int i=1;i<=q;i++)
    {
        cout<<1<<' '<<i<<'\n';
    }
    return 0;
}