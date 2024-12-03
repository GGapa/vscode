#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10; 
set<int> s;
int n,q,fi,a[N];
inline int sqrt(int x)
{
	int l=0,r=1e10;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(mid*mid<=x) l=mid;else r=mid-1;
	}
	return l;
}
signed main()
{
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++) 
	{
		scanf("%lld",&a[i]);
		if(a[i]) s.insert(i); 
	}
	while(q--)
	{
		int k,x;
		scanf("%lld%lld",&k,&x);
		if(a[k]) s.erase(s.find(k));
		a[k]=x;
		if(x) s.insert(k);
		int cur=(!s.empty()&&*s.begin()<max(1ll,n-40))?1:0;
		for(int i=max(1ll,n-40);i<=n;i++) cur=sqrt(cur+a[i]);
		printf("%lld\n",cur);
	}
	return 0;	
}
