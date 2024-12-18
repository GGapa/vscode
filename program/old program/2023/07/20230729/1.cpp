// Dalton the Teacher
//codeforces https://codeforces.com/contest/1855/problem/0

#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        int n,different=0;
        cin>>n;
        for(int i = 1;i<=n;i++)
        {
            int tmp;
            cin>>tmp;
            if(tmp==i)different++;
        }
        cout<<(different%2==0?different/2:different/2+1)<<'\n';
    }
    return 0;  
}