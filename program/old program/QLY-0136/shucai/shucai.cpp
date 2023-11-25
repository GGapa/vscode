#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
priority_queue<long long,vector<long long>,greater<long long> > A;
priority_queue<long long,vector<long long>,greater<long long> > B;
int a,b,c,m;
long long ans=0,num=0;
        int x;
        char y;
void init()
{
    scanf("%d %d %d",&a,&b,&c);
    scanf("%d",&m);
    for(int i = 0;i<m;i++)   
    {
        scanf("%d %c",&x,&y);
        if(y=='A')A.push(x);
        else B.push(x);
    }
}
int main()
{
    freopen("shucai.in","r",stdin);
    freopen("shucai.out","w",stdout);
    init();
    for(int i = 0;i<a;i++)
    {
        if(A.empty())break;
        ans+=A.top();
        num++;
        A.pop();
    }
    for(int i = 0;i<b;i++)
    {
        if(B.empty())break;
        ans+=B.top();
        num++;
        B.pop();
    }
    for(int i = 0;i<c;i++)
    {
        if(A.empty()&&B.empty())break;
        if(!A.empty()&&!B.empty())
        {
            if(A.top()<=B.top())
            {
                num++;
                ans+=A.top();
                A.pop();
            }
            else
            {
                num++;
                ans+=B.top();
                B.pop();
            }
        }
        else if(A.empty()&&!B.empty())
        {
            num++;
            ans+=B.top();
            B.pop();
        }
        else if(!A.empty()&&B.empty())
        {
            num++;
            ans+=A.top();
            A.pop();
        }
    }
    printf("%lld %lld",num,ans);
    return 0;
}