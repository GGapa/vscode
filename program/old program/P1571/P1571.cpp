//P1571 眼红的Medusa
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<int,int> person;
int a[100005];
int b[100005];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m );
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i = 1;i<=m;i++)
    {
        scanf("%d",&b[i]);
        person[b[i]]=1;
    }
    for(int i = 1;i<=n;i++)
    {
        if(person[a[i]]==1)printf("%d ",a[i]);
    }
    return 0;
}