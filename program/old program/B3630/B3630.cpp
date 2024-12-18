//B3630 排队顺序
#include <iostream>
#include <cstdio>
using namespace std;
int n,a[2000005];
int main()
{
    int it;
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
    }
    cin>>it;
    while(it!=0)
    {
        cout<<it<<" ";
        it=a[it];
    }
    return 0;
}