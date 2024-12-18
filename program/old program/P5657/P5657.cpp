//P5657 [CSP-S2019] 格雷码
#include <iostream>
using namespace std;

int main()
{
    int n;
    unsigned long long k;
    cin>>n>>k;
    k^=k>>1;
    while(--n>=0)cout<<(k>>n&1);
    return 0;
}