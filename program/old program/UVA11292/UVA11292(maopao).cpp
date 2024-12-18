//UVA11292 Dragon of Loowater
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
void so(int *a,int len)
{
    bool p=1;
    do
    {
        p=0;
        for(int i = 1;i<len;i++)
        {
            if(a[i]>a[i+1])
            {
                swap(a[i],a[i+1]);
                p=1;
            }
        }
    } while (p==1);
    
}
int main()
{
    int n,m;//n龙  m骑士
    int people[20005],dragon[20005];
    while(true)
    {
        int sum=0,successkilled=0;
        cin>>n>>m;
        if(n+m==0)return 0;
        memset(people,0,sizeof(people));
        memset(dragon,0,sizeof(dragon));
        for(int i = 1;i<=n;i++)
        {
            cin>>dragon[i];
        }
        for(int i = 1;i<=m;i++)
        {
            cin>>people[i];
        }

        if(n>m)//在不用printf和cstdio的前提下，没有这一段就会TLE
        {
            printf("Loowater is doomed!\n");
            continue;
        }

        so(dragon,n);
        so(people,m);
        int l=1;
        for(int i = 1;i<=m;i++)
        {
            if(people[i]>=dragon[l])
            {
                l++;
                successkilled++;
                sum+=people[i];
                if(l==n+1/*||successkilled>=n*/)break;
            }
        }
        if(successkilled<n)
        {
            cout<<"Loowater is doomed!"<<endl;
        }
        else
        {  
            cout<<sum<<endl;
        }
    }
    return 0;
}