#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
const int maxn = 1e5+5;
struct A
{
    ll index,first,second;
};
A a[maxn];
bool cmp(A x,A y)
{
    if(x.first==y.first)return x.second<y.second;
    return x.first<y.first;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i].first;
        a[i].index=i;
        a[i].second=a[i].first*i;
    }
    sort(a+1,a+1+n,cmp);
    for(int i = 1;i<=n;i++)cout<<a[i].index<<" ";
    cout<<"\n";
    return 0;
}