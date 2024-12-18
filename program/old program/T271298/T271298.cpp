// T271298 [CoE R5] 暴龙的白菜
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int t,num=1,ans=0,sum[1000005]={0};
    cin>>t;
    string a = "";
    stack<int> ls;
    while (a.length() <= 1000005)
    {
        for (int i = 1; ; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                a += to_string(i);
                if (a.length() > 1000005)
                    break;
            }
            if (a.length() > 1000005)
                break;
        }
    }
    //cout<<a<<endl;
    for(int i = 0;i<=1000000;i++)
    {
        sum[i]=sum[i-1]+a[i]-'0';
    }
    while(t--)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        l--;r--;
        cout<<sum[r]-sum[l-1]<<endl;
        ans=0;
    }
    return 0;
}
