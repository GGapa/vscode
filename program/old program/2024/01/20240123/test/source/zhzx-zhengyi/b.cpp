#include<bits/stdc++.h>
using namespace std;

constexpr int maxn=810,mod=1000000007;

int dp[maxn],cpy[maxn],pw[10][maxn];
vector<int>g1[maxn],g2[maxn];
vector<pair<int,int>>ch;
bool ok=true;

void dfs(int a,int b)
{
	int d1=1,d2=1;
	for(;g1[a].size()==1;a=g1[a][0],d1++);
	for(;g2[b].size()==1;b=g2[b][0],d2++);
	if(d1>d2||g1[a].size()!=g2[b].size())
	{
		ok=false;
		return;
	}
	ch.emplace_back(d1,d2);
	for(int i=0;i<(int)g1[a].size();i++) dfs(g1[a][i],g2[b][i]);
}

void vMul(const int *a,const int *b,int *c,int n)
{
	int i,j;
	memset(c,0,n*4+4);
	for(i=0;i<=n;i++)
	{
		if(!a[i]) continue;
		for(j=0;j<=n-i;j++)
		{
			c[i+j]=(c[i+j]+1ull*a[i]*b[j])%mod;
		}
	}
}

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int n1,n2,q,i,j,f,op,x;
	cin>>n1>>n2;
	for(i=2;i<=n1;i++) cin>>f,g1[f].push_back(i);
	for(i=2;i<=n2;i++) cin>>f,g2[f].push_back(i);
	dfs(1,1);
	cin>>q;
	if(!ok)
	{
		while(q--) cout<<"0\n";
		return 0;
	}
	sort(ch.begin(),ch.end());
	vector<int>s;
	while(q--)
	{
		cin>>op>>x;
		if(op==1)
		{
			s.push_back(x);
		}
		else
		{
			s.erase(lower_bound(s.begin(),s.end(),x));
		}
		sort(s.begin(),s.end());
		int ans=1,lst=0;
		memset(dp,0,sizeof dp);
		memset(pw[0],0,sizeof pw[0]);
		for(int it:s) pw[0][it]=1;
		for(i=1;i<=9;i++) vMul(pw[i-1],pw[i-1],pw[i],n2);
		dp[0]=1;
		for(auto it:ch)
		{
			int dt=it.first-lst;
			if(n2*n2*__builtin_popcount(dt)<dt*(n2-lst)*s.size())
			{
				while(dt)
				{
					i=__builtin_ctz(dt);
					memcpy(cpy,dp,n2*4+4);
					vMul(cpy,pw[i],dp,n2);
					dt-=1<<i;
				}
				lst=it.first;
			}
			else
			{
				for(;lst<it.first;lst++)
				{
					for(i=n2;i>=lst+1;i--)
					{
						dp[i]=0;
						for(j=0;j<(int)s.size()&&s[j]<=i;j++)
						{
							dp[i]+=dp[i-s[j]];
							if(dp[i]>=mod) dp[i]-=mod;
						}
					}
					dp[lst]=0;
				}
			}
			ans=1ull*ans*dp[it.second]%mod;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
