/*
停时定理板子？
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int md=998244353;
int quickPow(int x,int k)
{
	int ans=1;
	for(;k;k>>=1,x=x*x%md)
	{
		if(k&1)
			ans=ans*x%md;
	}
	return ans;
}
int n,m,q;
int f[110000];
int edf;
void getF()
{
	f[0]=0,f[1]=(quickPow(n,md-2)-1+md)%md;
	int im=quickPow(m,md-2),in1=quickPow(n-1,md-2),in=quickPow(n,md-2);
	for(int c=1;c<m;c++)
	{
		int x0=(c*im%md)*((((n-1)*m-(m-c))%md)*(im*in1%md)%md)%md;
		int x2=((m-c)*im%md)*((m-c)*(im*in1%md)%md)%md;
		int x1=(-x0-x2+2*md)%md;
		f[c+1]=((-in-f[c-1]*x0%md-f[c]*x1%md+3*md)%md)*quickPow(x2,md-2)%md;
	}
	// for(int c=0;c<=m;c++)
	// 	cout<<f[c]<<" ";
	// cout<<endl;
}
signed main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>q;
	if(n==1)
	{
		for(int i=1;i<=q;i++)
			cout<<0<<'\n';
		return 0;
	}
	getF();
	edf=(f[m]+(n-1)*f[0]%md)%md;
	for(int _=1;_<=q;_++)
	{
		int stf=0;
		for(int i=1;i<=n;i++)
		{
			int c;
			cin>>c;
			stf=(stf+f[c])%md;
		}
		cout<<(stf-edf+md)%md<<'\n';
	}
}
/*
2 3 2
0 3
1 2

1 5 4

2 100000 3
32948 90231
97495 18492
100000 8111
*/