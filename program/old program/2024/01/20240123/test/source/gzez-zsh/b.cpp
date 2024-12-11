#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define drep(i,a,b) for (int i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;
inline void setfile()
{
	#ifndef pbtxdy
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	#endif
}

const int mod=1e9+7;
inline int qmo(int x){return x+((x>>31)&mod);}
inline int add(int x,int y){return qmo(x+y-mod);}
inline int sub(int x,int y){return qmo(x-y);}
inline void inc(int &x,int y){x=add(x,y);}
inline void dec(int &x,int y){x=sub(x,y);}

const int N=810;

int n1,n2;
vector<int> G1[N],G2[N],V;

int main()
{
	setfile();
	ios::sync_with_stdio(false); cin.tie(0);

	cin>>n1>>n2;
	rep(i,2,n1)
	{
		int fa; cin>>fa;
		G1[fa].push_back(i);
	}
	rep(i,2,n2)
	{
		int fa; cin>>fa;
		G2[fa].push_back(i);
	}

	vector<array<int,2> > chains;
	queue<array<int,2> > q;
	q.push({1,1});
	bool gg=0;
	while (!q.empty())
	{
		auto it=q.front(); q.pop();
		int u=it[0],v=it[1],len1=1,len2=1;
		while (G1[u].size()==1) len1++,u=G1[u][0];
		while (G2[v].size()==1) len2++,v=G2[v][0];
		if (G1[u].size()!=G2[v].size()||len1>len2){gg=1; break;}
		chains.push_back({len1,len2});
		rep(i,0,(int)G1[u].size()-1) q.push({G1[u][i],G2[v][i]});
	}
	int LG=0;
	while ((1<<LG)<=n1) LG++;
	LG--;

	int Q; cin>>Q;
	rep(wtf,1,Q)
	{
		int op,x; cin>>op>>x;
		if (op==1) V.push_back(x);
		else V.erase(find(V.begin(),V.end(),x));
		if (gg)
		{
			printf("0\n");
			continue;
		}

		vector<vector<int> > f(LG+1,vector<int>(n2+1));
		for (auto x:V) if (x<=n2) f[0][x]=1;
		rep(bit,1,LG) rep(i,0,n2) if (f[bit-1][i]) rep(j,0,n2-i) if (f[bit-1][j]) inc(f[bit][i+j],1ll*f[bit-1][i]*f[bit-1][j]%mod);

		int ans=1;
		for (auto it:chains)
		{
			int x=it[0],y=it[1];
			vector<int> g(y+1); g[0]=1;
			rep(bit,0,LG) if (x&(1<<bit))
			{
				vector<int> ng(y+1);
				rep(i,0,y) if (g[i]) rep(j,0,y-i) if (f[bit][j]) inc(ng[i+j],1ll*g[i]*f[bit][j]%mod);
				swap(g,ng);
			}
			ans=1ll*ans*g[y]%mod;
			if (!ans) break;
		}
		printf("%d\n",ans);
	}

	return 0;
}
