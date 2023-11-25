//B3655 [语言月赛202208]天天爱跑步
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int v1,v3,v7,v30,v120,v365,n;
    scanf("%d",&n);
    scanf("%d%d%d%d%d%d",&v1,&v3,&v7,&v30,&v120,&v365);
    long long total=0,num=0;
    for(int i = 1;i<=n;i++)
    {
        bool x;
        cin>>x;
        total=((x==true)?(total+1):(0));
        if(total>=365)num+=v365;
        else if(total>=120)num+=v120;
        else if(total>=30)num+=v30;
        else if(total>=7)num+=v7;
        else if(total>=3)num+=v3;
        else if(total>=1)num+=v1;
    }
    printf("%lld",num);
    return 0;
}