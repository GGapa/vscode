#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<random>
#include<assert.h>
#define pb emplace_back
#define mp make_pair
#define fi first
#define se second
#define dbg(x) cerr<<"In Line "<< __LINE__<<" the "<<#x<<" = "<<x<<'\n'
#define dpi(x,y) cerr<<"In Line "<<__LINE__<<" the "<<#x<<" = "<<x<<" ; "<<"the "<<#y<<" = "<<y<<'\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
typedef pair<ll,int>pli;
typedef pair<ll,ll>pll;
typedef pair<int,ll>pil;
typedef vector<int>vi;
typedef vector<ll>vll;
typedef vector<pii>vpii;
typedef vector<pll>vpll;
template<typename T>T cmax(T &x, T y){return x=x>y?x:y;}
template<typename T>T cmin(T &x, T y){return x=x<y?x:y;}
template<typename T>
T &read(T &r){
	r=0;bool w=0;char ch=getchar();
	while(ch<'0'||ch>'9')w=ch=='-'?1:0,ch=getchar();
	while(ch>='0'&&ch<='9')r=r*10+(ch^48),ch=getchar();
	return r=w?-r:r;
}
template<typename T1,typename... T2>
void read(T1 &x,T2& ...y){read(x);read(y...);}
const int N=3010;
struct DS{
	int n,m;
	char s[N],t[N];
	int p[N][N],q[N][N],o[N][N];
	//LCS(s[i,j], t[1,k])
	void solve(){
		for(int i=0;i<=n;i++)p[i][0]=i+1;
		for(int i=0;i<=m;i++)q[0][i]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				const int P=p[i][j-1],Q=q[i-1][j];
				if(s[i]!=t[j]&&P>=Q)p[i][j]=P,q[i][j]=Q;
				else p[i][j]=Q,q[i][j]=P;
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				o[j][i]=p[i][j];
	}
}ds1,ds2;
int n,m,q;
char s[N],t[N];
struct Node{
	int a,b,c,d,id;
};
vector<Node>vec[N*4];
void modify(int x,int tl,int tr,Node &o){
	int mid=(tl+tr)>>1;
	if(o.b<=mid)modify(x<<1,tl,mid,o);
	if(o.a>mid)modify((x<<1)|1,mid+1,tr,o);
	vec[x].push_back(o);
}
int s1[N],s2[N],ans[100010];
void dfs(int x,int tl,int tr){
	if(tl==tr)return ;
	int mid=(tl+tr)>>1;
	if(!vec[x].empty()){
		ds1.m=0;
		for(int i=mid;i>=tl;i--)ds1.t[++ds1.m]=s[i];
		ds1.solve();
		
		ds2.m=0;
		for(int i=mid+1;i<=tr;i++)ds2.t[++ds2.m]=s[i];
		ds2.solve();
		for(auto o:vec[x]){
			int a=o.a,b=o.b,c=o.c,d=o.d,id=o.id;
			for(int i=c-1;i<=d+1;i++)s1[i]=s2[i]=0;
			for(int i=m-d+1;i<=m-c+1;i++){
				int l=m-i+1,r=m-ds1.o[mid-a+1][i]+1;
				s1[l]++,s1[r+1]--;
			}
			for(int i=c;i<=d+1;i++)s1[i]+=s1[i-1];
			for(int i=c;i<=d;i++){
				int l=max(c,ds2.o[b-mid][i]),r=i;
				if(l<=r)
					s2[l]++,s2[r+1]--;
			}
			for(int i=c;i<=d+1;i++)s2[i]+=s2[i-1];
			int mx=0;
			for(int i=c;i<=d+1;i++)
				mx=max(mx,s1[i-1]+s2[i]);
			ans[id]=mx;
		}
	}
	dfs(x<<1,tl,mid);
	dfs((x<<1)|1,mid+1,tr);
}
signed main(){
	//freopen("data.in","r",stdin);
	read(n);read(m);read(q);
	scanf("%s%s",s+1,t+1);
	ds1.n=0;
	for(int i=m;i>=1;i--)ds1.s[++ds1.n]=t[i];
	ds2.n=0;
	for(int i=1;i<=m;i++)ds2.s[++ds2.n]=t[i];
	for(int i=1;i<=q;i++){
		int a,b,c,d;read(a);read(b);read(c);read(d);
		Node o={a,b,c,d,i};
		if(a!=b)modify(1,1,n,o);
		else{
			for(int j=c;j<=d;j++)
				if(t[j]==s[a]){
					ans[i]=1;
					break;
				}
		}
	}
	dfs(1,1,n);
	for(int i=1;i<=q;i++)cout << ans[i] << '\n';
	return 0;
}
