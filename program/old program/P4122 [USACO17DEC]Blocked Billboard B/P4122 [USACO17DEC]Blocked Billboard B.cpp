//P4122 [USACO17DEC]Blocked Billboard B
#include <iostream>
using namespace std;
int map[2004][2004];
int x1,x2,y1,y2,ans=0;
void init()
{
    cin>>x1>>y1>>x2>>y2;
    x1+=1000;
    y1+=1000;
    x2+=1000;
    y2+=1000;
}
void add()
{
    for(int i = min(x1,x2);i<max(x1,x2);i++)
    {
        for(int j = min(y1,y2);j<max(y1,y2);j++)
        {
            ans++;
            map[i][j]=1;
        }
    }
}
int main()
{
    init();
    add();
    init();
    add();
    init();
    for(int i = min(x1,x2);i<max(x1,x2);i++)
    {
        for(int j = min(y1,y2);j<max(y1,y2);j++)
        {
            if(map[i][j]==1)ans--;
        }
    }
    cout<<ans<<endl;
    return 0;
}