#include<bits/stdc++.h>
using namespace std;
#define il inline
#define fi first
#define se second
#define lhx make_pair
#define eb emplace_back
#define rep(i,l,r) for(int i=(l); i<=(r); ++i)
#define rep_(i,l,r) for(int i=(l); i>=(r); --i)
typedef long long lr;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
constexpr int N=2020,mod1=998244353,mod2=1e9+7;
constexpr db eps=1e-7;
constexpr int inf32=0x3f3f3f3f,Inf32=0xcfcfcfcf;
constexpr lr inf64=0x3f3f3f3f3f3f3f3f,Inf64=0xcfcfcfcfcfcfcfcf;
template<typename T>il T Max(T x,T y)
{
    return (x>y)? x:y;
}
template<typename T>il T Min(T x,T y)
{
    return (x<y)? x:y;
}
template<typename T>il T gcd(T x,T y)
{
    return (!y)? x:gcd(y,x%y);
}
template<typename T>il T Abs(T x)
{
    return (x>0)? x:(-x);
}
struct tree
{
	int n,fa[N],dep[N],lst[N],len[N];
	vi v[N],w[N];
	il void pre1(int u)
	{
		if(u)
			dep[u]=dep[fa[u]]+1;
		for(int to:v[u])
			pre1(to);
		lst[u]=((int)v[u].size()==1)? lst[v[u][0]]:u;
	}
	il void pre2()
	{
		rep(u,0,n)
			if(!u||(int)v[u].size()!=1)
				for(int to:v[u])
					w[u].eb(lst[to]),len[lst[to]]=dep[lst[to]]-dep[u];
	}
};
int q,cnt,mx,mx2,lg2[N],xx[N],yy[N],id[N],k[N],kk[N],pw1[9][N],pw2[8][N];
tree a,b;
vi v;
il bool chk(int x,int y)
{
	if(x)
		xx[++cnt]=a.len[x],yy[cnt]=b.len[y],id[cnt]=cnt,mx=Max(mx,xx[cnt]),mx2=Max(mx2,yy[cnt]);
	if(a.w[x].size()!=b.w[y].size())
		return 0;
	rep(i,0,(int)a.w[x].size()-1)
		if(!chk(a.w[x][i],b.w[y][i]))
			return 0;
	return 1;
}
il void Solve()
{
	cin>>a.n>>b.n,a.v[0].eb(1),b.v[0].eb(1);
	rep(i,2,a.n)
		cin>>a.fa[i],a.v[a.fa[i]].eb(i);
	rep(i,2,b.n)
		cin>>b.fa[i],b.v[b.fa[i]].eb(i);
	a.pre1(0),a.pre2(),b.pre1(0),b.pre2(),cin>>q;
	if(!chk(0,0))
	{
		while(q--)
			cout<<0<<'\n';
		return;
	}
	int now=1,lg=0;
	while(now<=mx2)
		lg2[now]=lg,now<<=1,++lg;
	sort(id+1,id+1+cnt,[](int x,int y){return xx[x]<xx[y];}); 
	while(q--)
	{
		int op,x;
		cin>>op>>x,pw1[1][x]^=1,v.clear();
		rep(i,1,mx2)
			if(pw1[1][i])
				v.eb(i);
		rep(t,2,8)
		{
			rep(i,1,mx2)
				pw1[t][i]=0;
			rep(i,1,mx2)
				for(int j:v)
				{
					if(i+j>mx2)
						break;
					pw1[t][i+j]+=pw1[t-1][i],(pw1[t][i+j]>=mod2)? pw1[t][i+j]-=mod2:0;
				}
		}
		rep(i,1,mx2)
			pw2[0][i]=pw1[8][i];
		int num=8,t=0;
		while((num<<1)<=mx2)
		{
			++t; 
			rep(i,1,mx2)
				pw2[t][i]=0;
			rep(i,1,mx2)
			{
				if(!pw2[t-1][i])
					continue;
				rep(j,1,mx2-i)
					pw2[t][i+j]+=1ll*pw2[t-1][i]*pw2[t-1][j]%mod2,(pw2[t][i+j]>=mod2)? pw2[t][i+j]-=mod2:0;
			}
			num<<=1;
		}
		rep(i,1,mx2)
			k[i]=pw1[1][i];
		int lst=1,ans=1;
		rep(m,1,cnt)
		{
			if(xx[id[m]]*v[0]>yy[id[m]])
			{
				ans=0;
				break;
			}
			if(xx[id[m]]>lst)
			{
				int dif=xx[id[m]]-lst,dif2=dif>>3;
				while(dif2)
				{
					int cur=lg2[dif2&(-dif2)];
					rep(i,1,mx2)
						kk[i]=0;
					rep(i,1,mx2)
					{
						if(!k[i])
							continue;
						rep(j,1,mx2-i)
							kk[i+j]+=1ll*k[i]*pw2[cur][j]%mod2,(kk[i+j]>=mod2)? kk[i+j]-=mod2:0;
					}
					rep(i,1,mx2)
						k[i]=kk[i];
					dif2-=dif2&(-dif2);
				}
				dif&=7;
				if(dif==1)
				{
					rep(i,1,mx2)
						kk[i]=0;
					rep(i,1,mx2)
						for(int j:v)
						{
							if(i+j>mx2)
								break;
							kk[i+j]+=k[i],(kk[i+j]>=mod2)? kk[i+j]-=mod2:0;
						}
					rep(i,1,mx2)
						k[i]=kk[i];
				}
				if(dif>1)
				{
					rep(i,1,mx2)
						kk[i]=0;
					rep(i,1,mx2)
					{
						if(!k[i])
							continue;
						rep(j,1,mx2-i)
							kk[i+j]+=1ll*k[i]*pw1[dif][j]%mod2,(kk[i+j]>=mod2)? kk[i+j]-=mod2:0;
					}
					rep(i,1,mx2)
						k[i]=kk[i];
				}
			}
			lst=xx[id[m]],ans=1ll*ans*k[yy[id[m]]]%mod2;
		}
		cout<<ans<<'\n';
	}
}
int main()
{
#ifdef FILEIO
    string pre="b",isuf="in",osuf="out";
    freopen((pre+"."+isuf).c_str(),"r",stdin);
    freopen((pre+"."+osuf).c_str(),"w",stdout);
#endif
    ios::sync_with_stdio(0);
    int T=1;
    while(T--)
        Solve();
    return 0;
}
