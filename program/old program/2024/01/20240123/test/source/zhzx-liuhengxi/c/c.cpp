// created:  Jan/23/2024 09:55:39
#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void readmain(T &x)
{
	bool neg=false;unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
constexpr int N=1e5+5,MOD=998244353;
void reduce(int &x){(x>=MOD)&&(x-=MOD);}
int qpow(long long a,int b)
{
	long long c=1;
	for(;b;b>>=1,(a*=a)%=MOD)if(b&1)(c*=a)%=MOD;
	return (int)c;
}
int n,m,q,a[N],f[N],d1,d2,ivn;
int main()
{
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
#endif
#endif
	read(n,m,q);
	d1=qpow((long long)(n-1)*m%MOD,MOD-2);d2=qpow(m,MOD-2);
	f[0]=n-1;
	F(i,1,m)
	{
		int p1=(int)((long long)(m-i)*d1%MOD),p2=(int)((long long)i*d2%MOD);
		f[i]=(int)(((long long)p2*(MOD+1-p1)%MOD*f[i-1]+1)%MOD*qpow((long long)p1*(MOD+1-p2)%MOD,MOD-2)%MOD);
	}
	for(int i=m;~--i;)reduce(f[i]+=f[i+1]);
	ivn=qpow(n,MOD-2);
	while(q--)
	{
		int ans=0;
		F(i,0,n)reduce(ans+=f[read(a[i])]);
		ans=(int)((ans+(long long)(MOD+1-n)*f[0])%MOD*ivn%MOD);
		printf("%d\n",ans);
	}
	return 0;
}
