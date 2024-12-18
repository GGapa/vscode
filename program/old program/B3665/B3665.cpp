//B3665	小清新数据结构题
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define maxn 3000006
vector <unsigned int> a[maxn];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int n,q;
    unsigned int ans=0;
    cin>>n>>q;
    for(int i = 0;i<n;i++)
    {
        unsigned int temp;
        cin>>temp;
        for(int j = 0;j<temp;j++)
        {
            unsigned int x;
            cin>>x;
            a[i].push_back(x);
        }
    }
    for(int i = 0;i<q;i++)
    {
        unsigned int x,y;
        cin>>x>>y;
        if(ans!=0)ans^=a[x-1][y-1];
        else ans=a[x-1][y-1];
    }
    cout<<ans<<endl;
    return 0;
}