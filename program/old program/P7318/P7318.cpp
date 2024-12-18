//P7318 「PMOI-4」人赢の梦
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    long long n,m,k;
    cin>>n>>m>>k;
    long long a[10];
    a[1]=n;
    a[2]=m;
    for(int i = 3;i<=9;i++)
    {
        a[i]=((a[i-1]%10)*(a[i-2]%10))%10;
    }
    cout<<a[(k-3)%6+3]<<endl;
    return 0;
}