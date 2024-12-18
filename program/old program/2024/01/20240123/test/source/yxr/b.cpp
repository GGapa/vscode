#include<bits/stdc++.h>
using namespace std;
#define ll long long
namespace io{
	int read(){
		int sum=0,f=1;char a=getchar();
		while(a<'0'||a>'9'){if(a=='-')f=-1;a=getchar();}
		while(a>='0'&&a<='9')sum=sum*10+a-'0',a=getchar();
		return sum*f;
	}
	void print(int x){
		if(x<0)putchar('-'),x=-x;
		if(x>9)print(x/10);
		putchar(x%10+48);
	}
}
const int N=1000,p=1e9+7;
struct tree{
	int n;
	vector<int> e[N],ed[N];
	bool vi[N];int cnt[N],val[N];
	void in(){
		e[0].push_back(1);
		for(int i=2;i<=n;++i){int x=io::read();e[x].push_back(i);}
	}
	void dfs(int x,int pre,int co){
		if(e[x].size()!=1)vi[x]=1,ed[pre].push_back(x),cnt[x]=co+1;
		if(x&&e[x].size()==1)++co;else co=0,pre=x;
		for(auto y:e[x])dfs(y,pre,co);
	}
}t1,t2;
ll f[N][N];int n,m;
bool ch(int x,int y){
	if(t1.ed[x].size()!=t2.ed[y].size())return 0;
	t1.val[x]=t2.cnt[y],t2.val[y]=t1.cnt[x];n=max(n,t1.cnt[x]),m=max(m,t1.val[x]);
	for(int i=0;i<t1.ed[x].size();++i)if(!ch(t1.ed[x][i],t2.ed[y][i]))return 0;
	return 1;
}
set<int> s;
signed main(){
	
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	t1.n=io::read(),t2.n=io::read();
	t1.in(),t2.in();
	t1.dfs(0,0,0),t2.dfs(0,0,0);
	int q=io::read();
	if(!ch(0,0)){while(q--)puts("0");return 0;}
	f[0][0]=1;
	while(q--){
		int opt=io::read(),x=io::read();
		if(opt==1)s.insert(x);else s.erase(x);
		ll res=1;
		for(int i=0;i<=n;++i)for(int j=0;j<=m;++j)f[i][j]=0;f[0][0]=1;
		for(int i=1;i<=n;++i){
			for(auto w:s)for(int j=w;j<=m;++j)(f[i][j]+=f[i-1][j-w])%=p;
		}
		for(int i=1;i<=t1.n;++i)
			if(t1.vi[i])res=res*f[t1.cnt[i]][t1.val[i]]%p;
		io::print(res),puts("");
	}

	return 0;
}