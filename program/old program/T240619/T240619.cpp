#include <iostream>
#include <string>
using namespace std;
string ans1="01100",ans2="1100";
int main()
{
    int n;
    scanf("%d",&n);
    if(n==5)
    {
        cout<<ans1<<endl;
    }
    else if((n-5)%4==0)
    {
        cout<<ans1;
        int len=(n-5)/4;
        for(int i = 1;i<=len;i++)
        {
            cout<<ans2;
        }
    }
    else{
        cout<<-1<<endl;
    }
    return 0;
}