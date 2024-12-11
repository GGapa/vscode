#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1605;
const int MOD=1e9+7;
struct Tree{
	vector<int>vec[N];
	int h[N],tot;
	int n;
	int fa[N];
	int son[N];
	void dfs(int start,int father){
		fa[start]=father;
		son[start]=vec[start].size();
		for(int i=0;i<son[start];i++){
			dfs(vec[start][i],start);
		} 
	}
}t1,t2;
int f[N][N];
int d[N][N];
int C[N][N];
bool can[N];
int B;
int dp(int start1,int start2){
	//cout<<start1<<" "<<start2<<"\n";
	if(t1.son[start1]==0){
		int len=0;
		while(t2.son[start2]==1){
			start2=t2.vec[start2][0];
			len++;
		}
		if(!can[len+1])return 0; 
		return 1;
	}
	if(t1.son[start1]!=1){
		int len=0;
		while(t2.son[start2]==1){
			start2=t2.vec[start2][0];
			len++;
		}
		if(!can[len+1])return 0; 
		if(t1.son[start1]!=t2.son[start2])return 0;
		int ans=1;
		for(int i=0;i<t1.son[start1];i++){
			ans=ans*dp(t1.vec[start1][i],t2.vec[start2][i])%MOD;
		}
		return ans;
	}
	int len1=0;
	while(t1.son[start1]==1){
		start1=t1.vec[start1][0];
		len1++;
	}
	int len2=0;
	while(t2.son[start2]==1){
		start2=t2.vec[start2][0];
		len2++;
	}
	if(t1.son[start1]!=t2.son[start2])return 0;
	int ans=0;
	for(int i=0;i<=len2+1;i++){
		for(int j=0;j<=len1+1;j++){
			if(j>i)break;
			//cout<<i<<" "<<j<<" "<<f[i][j]<<" "<<d[len2+1-i][len1+1-j]<<" "<<C[len1+1][j]<<"\n";
			ans+=f[i][j]*d[len2+1-i][len1+1-j]%MOD*C[len1+1][j]%MOD;
			ans%=MOD;
		}
	}
	//cout<<len1+1<<" "<<len2+1<<" "<<ans<<"\n";
	for(int i=0;i<t1.son[start1];i++){
		ans=ans*dp(t1.vec[start1][i],t2.vec[start2][i])%MOD;
	}
	return ans;
}
signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%lld%lld",&t1.n,&t2.n);
	C[1][0]=1;
	C[1][1]=1;
	for(int i=2;i<=t2.n;i++){
		for(int j=0;j<=i;j++){
			if(j==0)C[i][j]=1;
			else C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
		}
	}
	for(int i=1;i<t1.n;i++){
		int v;
		scanf("%lld",&v);
		t1.vec[v].push_back(i+1);
	}
	for(int i=1;i<t2.n;i++){
		int v;
		scanf("%lld",&v);
		t2.vec[v].push_back(i+1);
	}
	for(int i=1;i<=t1.n;i++){
		sort(t1.vec[i].begin(),t1.vec[i].end());
	}
	for(int i=1;i<=t2.n;i++){
		sort(t2.vec[i].begin(),t2.vec[i].end());
	}
	t1.dfs(1,0);
	t2.dfs(1,0);
	int n=t2.n;
	//B=n;
	//B=0;
	B=pow(n,0.3333);
	//cout<<"B:"<<B<<"\n"; 
	int q;
	scanf("%lld",&q);
	f[0][0]=1;
	d[0][0]=1;
	for(int i=1;i<=q;i++){
		int op,x;
		scanf("%lld%lld",&op,&x);
		if(op==1){
			//cout<<"+ "<<x<<"\n";
			can[x]=1;
			if(x<=B){
				d[0][0]=1;
				for(int j=1;j<=n;j++){
					for(int k=1;k<=n;k++){
						d[j][k]=0;
						for(int l=1;l<=B&&l<=j;l++){
							if(can[l]){
								d[j][k]+=d[j-l][k-1];
								d[j][k]%=MOD;
							}
						}
						d[j][k]%=MOD;
					}
				}
			}
			else{
				for(int j=n;j>=x;j--){
					for(int k=1;k<=n/(B+1)+1;k++){
						for(int l=1;l<=j/x;l++){
							if(l>k)break;
							f[j][k]+=f[j-l*x][k-l]*C[k][l]%MOD;
							f[j][k]%=MOD;
							//if(f[j][k]<0)cout<<"?\n";
						}
					}
				}
			}
		}
		else{
			//cout<<"- "<<x<<"\n";
			can[x]=0;
			if(x<=B){
				d[0][0]=1;
				for(int j=1;j<=n;j++){
					for(int k=1;k<=n;k++){
						d[j][k]=0;
						for(int l=1;l<=B&&l<=j;l++){
							if(can[l]){
								d[j][k]+=d[j-l][k-1];
								d[j][k]%=MOD;
							}
						}
						d[j][k]%=MOD;
					}
				}
			}
			else{
				for(int j=x;j<=n;j++){
					for(int k=1;k<=n/(B+1)+1;k++){
						for(int l=1;l<=j/x;l++){
							if(l>k)break;
							f[j][k]=(f[j][k]-f[j-l*x][k-l]*C[k][l]%MOD+MOD)%MOD;
							//if(f[j][k]<0)cout<<"?\n";
						}
					}
				}
			}
		}
		cout<<dp(1,1)<<"\n";
	}
	return 0;
}
