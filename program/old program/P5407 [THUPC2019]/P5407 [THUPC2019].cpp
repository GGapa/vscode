#include <iostream>
using namespace std;

int main()
{
    int n,ans=12,date=3;
    cin>>n;
    for(int i = 2019;i>n;i--)
    {
        if(i%400==0||(i%100!=0&&i%4==0))
        {
            ans+=2;
        }
        else
        {
            ans+=1;
        }
        if(ans>14)ans-=7;
    }
    cout<<ans<<endl;
    return 0;
}