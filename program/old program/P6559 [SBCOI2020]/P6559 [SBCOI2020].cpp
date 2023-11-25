#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
map<int,map<int,int> > m;

int main()
{
    int n,k,ans=0;
    cin>>n>>k;
    for(int i =1;i<=k;i++)
    {
        int x,y;
        cin>>x>>y;
        m[x][y]++;
        if(m[x+1][y]==1)ans++;
        if(m[x][y+1]==1)ans++;
        if(m[x-1][y]==1)ans++;
        if(m[x][y-1]==1)ans++;
    }
    cout<<ans<<endl;
    return 0;
}