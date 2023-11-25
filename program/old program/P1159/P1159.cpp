//P1159 排行榜
#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
using namespace std;
queue<string>up,down;
string name[101];
bool same[101];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        string input;
        cin>>name[i]>>input;
        if(input=="UP")up.push(name[i]);
        else if(input=="SAME")same[i]=true;
        else down.push(name[i]);
    }
    for(int i = 1;i<=n;i++)
    {
        if(same[i])
        {
            cout<<name[i]<<endl;
        }
        else
        {
            if(!down.empty())cout<<down.front()<<endl,down.pop();
            else if(!up.empty())cout<<up.front()<<endl,up.pop();
        }
    }
    return 0;
}