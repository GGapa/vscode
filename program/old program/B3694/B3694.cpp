//B3694 数列离散化
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(auto &i:a)cin>>i;
        b=a;
        sort(b.begin(),b.end());
        auto c=unique(b.begin(),b.end());
        for(auto x:a)
        {
            int rank=lower_bound(b.begin(),c,x)-b.begin()+1;
            cout<<rank<<" ";

        }
        cout<<endl;

    }
}