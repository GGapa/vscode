#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll _=805,M=1e9+7;
inline void pls(ll &x,ll y){x+=y;x=(x<M?x:x-M);}
ll n,m,k,q,x,y,s,a[_],b[_],c[_],d[_][_],i,j,g;bool f[_];
struct Tree{
	ll n,rt,a[_],b[_];vector<ll>E[_];
	void p(ll x){
		if(E[x].size()==1)p(E[x][0]),a[x]=a[E[x][0]];
		else{a[x]=x;for(auto &y:E[x])p(y),y=a[y];}
		b[a[x]]++;
	}
	void init(){for(i=2;i<=n;i++)cin>>x,E[x].emplace_back(i);p(1);rt=a[1];}
}A,B;
bool p(ll x,ll y){
	if(A.E[x].size()!=B.E[y].size())return 0;
	a[++n]=A.b[x];b[n]=B.b[y];if(a[n]>b[n])return 0;
	for(ll i=A.E[x].size();i--;)if(!p(A.E[x][i],B.E[y][i]))return 0;
	return 1;
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>A.n>>B.n;A.init();B.init();cin>>q;
	if(!p(A.rt,B.rt)){while(q--)cin>>x>>y,cout<<"0\n";return 0;}
	for(i=1;i<=n;i++)m=max(m,a[i]),k=max(k,b[i]),c[a[i]]=max(c[a[i]],b[i]);
	for(i=m;~i;i--)c[i]=max(c[i],c[i+1]-1);
	while(q--){
		cin>>x>>y;if(x==1)f[y]=1;else f[y]=0;
		memset(d,0,sizeof(d));d[0][0]=1;
		for(g=1;g<=m;g++)for(i=1;i<=k;i++)if(f[i])
			for(j=g-1+i;j<=c[g];j++)pls(d[g][j],d[g-1][j-i]);
		for(s=i=1;i<=n;i++)s=s*d[a[i]][b[i]]%M;
		cout<<s<<'\n';
	}
}
