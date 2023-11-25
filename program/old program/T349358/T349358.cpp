//T349358 [yLOI2022] 签到题
#include <iostream>
#include <cstdio>
using namespace std;

int ans1,ans2,ans3;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a;
    cin>>a;
    
    for(int i = 0;i<a.length();i++)
    {
        if('0'<=a[i]&&a[i]<='9')ans1++;
        else if('a'<=a[i]&&a[i]<='z')ans2++;
        else ans3++;
    }
    cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
    return 0;
}