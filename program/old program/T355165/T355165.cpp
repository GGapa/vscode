// T355165 小情侣和单身狗 (dog)
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 5e6 + 5;

int a[maxn], n,b[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        a[i] = i;
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin>>tmp;
        int l=max(1,i-tmp);
        int r= min(n,i+tmp);
        a[r]=min(a[r],l);
    }
    int index;
    for(int i = 1;i<=n;i++)
    {
        while(index>0&&b[index-1]>=a[i]-1)index--;
        b[++index]=i;
    }
    cout<<index<<endl;
    return 0;
}