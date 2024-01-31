#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
inline int read()
{   int x=0;
    bool f=0;
    char c=getchar();
    while(!isdigit(c))f|=(c=='-'),c=getchar();
    while(isdigit(c))x=x*10+(c&15),c=getchar();
    return f?-x:x;
}
using namespace std;
int n1,n2,q,dl[805],tot,f[805][805],cnt1,cnt2,id1[805],id2[805],dep1[805],dep2[805],maxn;
vector<int> to1[805],to2[805],t1[805],t2[805];
void dfs(int x,int fa,int FA)
{   dep1[x]=dep1[FA]+1;
	if(to1[x].size()>=2||to1[x].size()==0)
	{	cnt1++;
		id1[cnt1]=x;
		t1[fa].push_back(cnt1);
		maxn=max(maxn,dep1[x]-dep1[id1[fa]]);
		fa=cnt1;
	}
    for(auto y:to1[x])dfs(y,fa,x);
    return ;
}
void DFS(int x,int fa,int FA)
{   dep2[x]=dep2[FA]+1;
	if(to2[x].size()>=2||to2[x].size()==0)
	{	cnt2++;
		id2[cnt2]=x;
		t2[fa].push_back(cnt2);
		maxn=max(maxn,dep2[x]-dep2[id2[fa]]);
		fa=cnt2;
	}
    for(auto y:to2[x])DFS(y,fa,x);
    return ;
}
bool check()
{	for(int i=0;i<=cnt1;++i)
		for(int j=0;j<t1[i].size();++j)
			if(t1[i][j]!=t2[i][j])return 0;
	return 1;
}
signed main()
{   freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
	n1=read(),n2=read();
	for(int i=2,x;i<=n1;++i)
	{   x=read();
    	to1[x].push_back(i);
	}
	for(int i=2,x;i<=n2;++i)
	{   x=read();
    	to2[x].push_back(i);
	}
	dfs(1,0,0);
	DFS(1,0,0);
	if(cnt1!=cnt2||check()==0)
	{	q=read();
		while(q--)printf("0\n");
		return 0;
	}
	q=read();
	while(q--)
	{	int opt=read(),x=read();
		if(opt==1)dl[++tot]=x;
		else
		{	for(int i=1;i<=tot;++i)
				if(dl[i]==x)
				{	swap(dl[i],dl[tot]);
					break;
				}
			tot--;
		}
//		int maxn=max(n1,n2);
		for(int i=0;i<=maxn;++i)
			for(int j=0;j<=maxn;++j)f[i][j]=0;
		f[0][0]=1;
		for(int i=0;i<maxn;++i)
			for(int k=1;k<=tot;++k)
				for(int j=0;j+dl[k]<=maxn;++j)
					(f[i+1][j+dl[k]]+=f[i][j])%=mod;
		int ans=1;
		for(int i=0;i<=cnt1;++i)
			for(int j=0;j<t1[i].size();++j)
				(ans*=f[dep1[id1[t1[i][j]]]-dep1[id1[i]]][dep2[id2[t2[i][j]]]-dep2[id2[i]]])%=mod;
		printf("%lld\n",ans);
	}
	return 0;
}
