//CF2A winner

#include <iostream>
#include <map>
#include <cstdio>
#include <string>
#include <limits>
#include <queue>
using namespace std;
pair<int,int> p(-1,-1);
map<string,int > pe,pee;
string name[10005];
int maxn =INT_MIN,a[10005];
string maxname;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        cin>>name[i]>>a[i];
        pe[name[i]]+=a[i];
    }
    for(int i = 1;i<=n;i++)
    {
        maxn=max(maxn,pe[name[i]]);
    }   
    for(int i = 1;i<=n;i++)
    {
        pee[name[i]]+=a[i];
        if(pee[name[i]]>=maxn&&pe[name[i]]==maxn)
        {
            cout<<name[i]<<endl;
            return 0;
        }
    }
    return 0;
}