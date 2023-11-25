#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[100005];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n,cmp);
    for(int i = 0;i<n;i++)
    {
        if(a[i]<i)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<n<<endl;
    return 0;
}