#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int a[100005],b[100005];
    for(int i = 1;i<=n;i++)cin>>a[i];
    for(int i = 1;i<=n;i++)
    {
        b[i]=b[i-1]+a[i];
    }
    int m;
    cin>>m;
    while(m--)
    {
        int o1,o2;
        cin>>o1>>o2;
        cout<<b[o2]-b[o1-1]<<endl;
    }
    return 0;

}