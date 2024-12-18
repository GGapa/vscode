#include <iostream>
#include <queue>
#include <algorithm>
#include <functional> 
using namespace std;
typedef pair<int ,int >p;
priority_queue < p, vector < p > , less < p > > q;
//priority_queue<int,vector<int > ,greater<int > >q;

int n,k,a[2000005];

int main()
{

    cin>>n>>k;
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i = 0;i<n;i++)
    {
        q.push(make_pair(a[i],i));
        if(q.size()>=k)
        {
            while(q.top().second<=i-k)
			{
				q.pop();
			}
            cout<<q.top().first <<endl;
        }
    }
    return 0;
}
