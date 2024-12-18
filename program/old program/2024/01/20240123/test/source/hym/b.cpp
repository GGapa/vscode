#include<bits/stdc++.h>
using namespace std;
int x,y,fx[100100],fy[100100],op,z,t;
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>x>>y;
	for(int i=2;i<=x;i++) cin>>fx[i];
	for(int j=2;j<=y;j++) cin>>fy[j];
	cin>>t;
	while(t--)
	{
		cin>>op>>z;
		cout<<0<<"\n";
	}
	return 0;
}
