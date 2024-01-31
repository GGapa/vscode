#include<bits/stdc++.h>
using namespace std;
//#define int long long 
const long long  NN=1e9+7;
vector<int>g1[200200],g2[200200];
int ans,fa1[100100],fa2[100100];
long long  f[810][810];
int n1,n2,q;
int used[100100];
long long  p[100100],ni[100100];
int mx1=0,mx2=0;
void dfs(int x,int xx){
	if (g2[xx].size()==1){
		int zong1=0,zong2=0;
		while(g1[x].size()==1)zong1++,x=g1[x][0];
		while(g2[xx].size()==1)zong2++,xx=g2[xx][0];
		zong1++;zong2++;
		mx1=max(mx1,zong1);mx2=max(mx2,zong2);
		ans=ans*f[zong2][zong1]%NN*p[zong1]%NN;
	}else if (used[1]==0)ans=0;
	if (g2[xx].size()!=g1[x].size())return ans=0,void();
	for (int i=0;i<g1[x].size();i++)dfs(g1[x][i],g2[xx][i]);
}
int mi(int x,int y){
	int sum=1;
	for (;y;y>>=1,x=1ll*x*x%NN)
	if (y&1)sum=1ll*sum*x%NN;
	return sum;
}
int get(int x){
	if (x<0)return x+NN;
	if (x>=NN)return x-NN;
	return x;
}
int ls[880][880];
int rs[880][880];
int col[880][880];
int use[880][880];
signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n1>>n2;
	for (int i=2,x;i<=n1;i++)	
	cin>>x,g1[x].push_back(i);
	for (int i=2,x;i<=n2;i++)
	cin>>x,g2[x].push_back(i);
	cin>>q;
	int op,x;
	int n=max(n1,n2);
	p[0]=1;for (int i=1;i<=n;i++)p[i]=1ll*p[i-1]*i%NN;
	ni[n]=mi(p[n],NN-2);for (int i=n;i;i--)ni[i-1]=1ll*ni[i]*i%NN;
	dfs(1,1);
	f[0][0]=1;
	for (int ii=1;ii<=n;ii++){
		int zong=0;
		for (int i=1;;i++){
			ls[ii][++zong]=(i-1)*20;
			rs[ii][zong]=min(i*20-1,n);
			for (int j=ls[ii][zong];j<=rs[ii][zong];j++)
			col[ii][j]=zong;
			if (i*20-1>=n)break;
		}
	}
	while(q--){
		cin>>op>>x;
		int mx=1;
		for (int i=1;i<=n;i++)
		if (used[i])mx=i;
		ans=1;
		if (op==1){
			used[x]=1;
			for(int j=mx2;j>=0;j--)for (int ii=1;ii*x+j<=mx2&&ii<=mx1;ii++){
				int t=ii*x+j,tt=min(mx1-ii,j);
				for (int k=j/mx;k<=tt;k++)if (f[j][k]){
					f[t][ii+k]=(f[t][ii+k]+f[j][k]*ni[ii])%NN;
					use[t][col[t][ii+k]]++;
				}else if (!use[j][col[j][k]])k=rs[j][col[j][k]]+1;
			}
		}
		else if (op==2){
			used[x]=0;
			for(int j=0;j<=mx2;j++)for(int ii=1;ii*x+j<=mx2&&ii<=mx1;ii++){
				int t=ii*x+j,tt=min(mx1-ii,j);
				for (int k=j/mx;k<=tt;k++)if (f[j][k]){
					f[t][ii+k]=get(f[t][ii+k]-f[j][k]*ni[ii]%NN);
					if (!f[t][ii+k])use[t][col[t][ii+k]]--;
				}else if (!use[j][col[j][k]])k=rs[j][col[j][k]]+1;
			}
		}
		dfs(1,1);
		cout<<ans<<"\n";
//		return 0;
	}
} 
