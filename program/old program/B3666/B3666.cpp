//B3666 求数列所有后缀最大值的位置
#include <iostream>
#include <stack>
using namespace std;
#define ull unsigned long long
ull n,ans=0,a[1000005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    stack<ull> s;
    for(int i = 1;i<=n;i++)
    {
        ull x;
        cin>>x;
        while(!s.empty()&&a[s.top()]<=x)
        {
            ans^=s.top();
            s.pop();
        }
        
        s.push(i);
        a[i]=x;
        ans^=s.top();
        cout<<ans<<endl;
    }
    return 0;
}