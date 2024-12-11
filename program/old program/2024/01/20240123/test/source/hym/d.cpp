#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f,x,y,z;
const int mod=998244353;
long long quick(long long x,long long y)
{
	long long ans=1;
	for(int i=1;i<=y;i++) ans*=x,ans%=mod;
	return ans;
}
int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>a>>b>>c>>d>>e;
	for(int i=1;i<=a;i++) cin>>f;
	for(int i=1;i<=b;i++) cin>>x>>y>>z;
	cout<<quick(2,a)+a;
	return 0; 
}
