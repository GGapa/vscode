#include <iostream>
#include <cstdio>
using namespace std;
const int mod = 1e9+7;

int n,m,k,c;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k>>c;
    cout<<n*m%mod<<endl;
    return 0;
}