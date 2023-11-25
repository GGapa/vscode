#include <iostream>
using namespace std;

int main()
{
    int a,b,ans=0;
    cin>>a>>b;
    for(int i = a;i<=b;i++)
    {
        if(i%2!=0||i%4==0)ans++;
    }
    cout<<ans<<endl;
    return 0;
}
