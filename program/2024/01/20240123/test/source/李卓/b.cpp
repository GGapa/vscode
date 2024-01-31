#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
const int mx=1005,mod=1e9+7;
int q,dp[805][805];
vector <int> f;
struct tree{
	int n,fa[mx],d[mx],len[mx];
	vector <int> p[mx],up[mx];
} T[2];
int read(){
	int num=0,w=1;char c;
	while(1){
		c=getchar();
		if((c=='-')||(c>='0'&&c<='9')) break;
	}
	if(c=='-') w=-1;
	else num=c-'0';
	while(1){
		c=getchar();
		if(!(c>='0'&&c<='9')) break;
		num=num*10+c-'0';
	}
	return num*w;
}
//void wt(int x){
//	if(x<0) putchar('-'),wt(-x);
//	else if(x>9) wt(x/10),putchar(x%10+'0');
//	else putchar(x+'0');
//}
int add(int x){
	return (x>=mod)?x-mod:x;
}
void dfs(int x){
	for(auto y:T[0].p[x]){
		dfs(y);
	}
	for(int i=1;i<=T[1].n;++i){
		int sum=1;
		if(T[1].d[i]==T[0].d[x]){
			for(int j=0;j<(int)T[0].p[x].size();++j)
				sum=(sum*dp[T[0].p[x][j]][T[1].p[i][j]])%mod;
			if(sum==0)
				continue;
			for(auto xx:f){
				if((int)T[1].up[i].size()>=xx){
					int y=T[1].up[i][xx-1];
					dp[x][y]=add(dp[x][y]+sum);
				}
				else break;
			}
		}
	}
}
signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	T[0].n=read();T[1].n=read();
    for(int i=2;i<=T[0].n;++i){
    	int x=read();
		T[0].fa[i]=x;
    	T[0].p[x].push_back(i);
    	++T[0].d[x];
	}
    for(int i=2;i<=T[1].n;++i){
    	int x=read();
		T[1].fa[i]=x;
    	T[1].p[x].push_back(i);
    	++T[1].d[x];
	}
	for(int i=1;i<=T[1].n;++i){
		T[1].up[i].push_back(i);
		if(T[1].d[T[1].fa[i]]==1){
			for(auto x:T[1].up[T[1].fa[i]])
				T[1].up[i].push_back(x);
		}
	}
	q=read();
	while(q--){
		int opt=read(),x=read();
		if(opt==1) f.push_back(x);
		else
			for(int i=0;i<(int)f.size();++i)
				if(f[i]==x)
					{swap(f[i],f.back());f.pop_back();break;}
		sort(f.begin(),f.end());
		dfs(1);
//		for(int i=1;i<=5;++i,cout<<endl)
//			for(int j=1;j<=8;++j)
//				cout<<dp[i][j]<<" ";
		printf("%lld\n",dp[1][1]);
//		wt(dp[1][1]);puts("");
		memset(dp,0,sizeof(dp));
	}
    fclose(stdin);fclose(stdout);
    return 0;
}
