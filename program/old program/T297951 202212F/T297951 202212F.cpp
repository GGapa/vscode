//T297951 202212F 宇宙密码
#include  <iostream>
#include  <string>
#include <algorithm>
using namespace std;

int main()
{
    int n,k;
    string ls="",a="",ans[100],ne;
    cin>>n>>ls>>k;
    for(int i = ls.length();i<=n;i++)
    {
        a+=
    }
    for(int i = 0;i<n;i++)
    {
        a+=ls[i]-'0';
    }
    int it=0;
    for(int i = 0;i<ls.length();i++)
    {
        ne=ls;
        ne[i]=abs(ne[i]-k)%58;
        ans[it++]=ne;
        ne[i]=abs(ne[i]+k)%58;
        ans[it++]=ne;
    }
    sort(ans,ans+it);
    for(int i = 0;i<it;i++)
    {
        bool zero=true;
        for(int j = 0;j<n;j++)
        {
            if(ans[i][j]!='0')zero=false;
            if(!zero)cout<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;

}