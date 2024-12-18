//P1886 滑动窗口 /【模板】单调队列
#include <iostream>
#include <queue>
using namespace std;
long long ans[2][1000006],n,k,a[1000006],num=0;
typedef pair<int ,int >p;
priority_queue<p,vector<p > ,greater<p > >qmax;//max
priority_queue<p,vector<p > ,less<p > >qmin;//min
int main()
{
	cin>>n>>k;
	for(int i = 0;i<n;i++)cin>>a[i];
	for(int i = 0;i<n;i++)
    {
        qmax.push(make_pair(a[i],i));
        if(qmax.size()>=k)
        {
            while(qmax.top().second<=i-k)
			{
				qmax.pop();
			}
            ans[0][num]=qmax.top().first;
        }
        qmin.push(make_pair(a[i],i));
        if(qmin.size()>=k)
        {
            while(qmin.top().second<=i-k)
			{
				qmin.pop();
			}
            ans[1][num++]=qmin.top().first;
        }
    }
    for(int i = 0;i<num;i++)
    {
    	cout<<ans[0][i]<<" " ;
    }
    cout<<endl;
    for(int i = 0;i<num;i++)
    {
    	cout<<ans[1][i]<<" ";
    }
    return 0;
}
