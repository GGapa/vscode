#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int tento8(int x)
{
    int re = 0, tmp;
    string ans;
    while (x != 0)
    {
        tmp = x % 8;
        x /= 8;
        ans=char(tmp+'0')+ans;
    }
    for(int i = 0;i<ans.length();i++)
    {
        re=re*10+(ans[i]-'0');
    }
    return re;
}

int main()
{
    string a1;
    int a=0,h;
    cin>>a1>>h;
    for(int i = 0;i<a1.length();i++)
    {
        a+=(a1[i]-'0')*pow(8,a1.length()-1-i);
    }

    int kg=h*3-3,wide=1;
    for(int i = 1;i<=h;i++)
    {
        for(int j = 1;j<=kg;j++)
        {
            cout<<" ";
        }
        kg-=3;
        for(int j = 1;j<=wide;j++)
        {
            if(wide!=1)a+=i;
            printf("%-6d",tento8(a));
        }
        wide++;
        cout<<endl;
    }
    return 0;
}