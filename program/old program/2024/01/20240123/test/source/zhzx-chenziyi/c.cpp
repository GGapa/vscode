#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int NN=998244353;
int n,m,t;
int a[100100];
int mi(int x,int y){
	int sum=1;
	for (;y;y>>=1,x=x*x%NN)
	if (y&1)sum=sum*x%NN;
	return sum;
}
signed main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>n>>m>>t;
	int t1=mi(m,NN-2),t2=mi((n-1)*m,NN-2);
	while(t--){
		for (int i=1;i<=n;i++)
		cin>>a[i];
		int ans=0,mx=0;
		for (int i=1;i<=n;i++)
		mx=max(mx,a[i]);
		for (int j=mx;j<m;j++)
		ans=(ans+mi((m-j)%NN*t1%NN*(m-j)%NN*t2%NN,NN-2))%NN;
		cout<<ans<<"\n";
	}
}
