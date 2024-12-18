//P7001 [NEERC2013] Fraud Busters
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
queue<string> aa;
int main()
{
    string a;
    int n,ans=0;
    cin>>a;
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        string b;
        bool bj=true;
        cin>>b;
        for(int i = 0;i<9;i++)
        {
            if(a[i]!=b[i]&&a[i]!='*')
            {
                bj=false;
                break;
            }
        }
        if(bj)ans++,aa.push(b);
    }
    cout<<ans<<endl;
    while(!aa.empty())
    {
        cout<<aa.front()<<endl;
        aa.pop();
    }
    return 0;
}