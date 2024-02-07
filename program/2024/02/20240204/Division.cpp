/**
 * @Problem      : 
 * @URL          : 
 * @Author       : GGapa
 * @Date         : 2024-02-04 19:57:35
 * @LastEditTime : 2024-02-04 19:57:37
**/
#include<bits/stdc++.h>
using namespace std;
int ans,sum1[5],sum2[5],vis[10],u[10];
int n;
bool check(){
	for(int i=4;i>=0;i--){
		sum2[i]+=sum1[i]*n;
		if(i==0&&sum2[i]>=10){
			return false;
		}
		if(sum2[i]>=10)sum2[i-1]+=sum2[i]/10,sum2[i]%=10;
		if(vis[sum2[i]]||u[sum2[i]])return false;
		u[sum2[i]]=true;
	}
	return true;
}
void dfs(int dep){
	if(dep==5){		
		if(check()){
			ans++;
			for(int i=0;i<=4;i++)
				printf("%d",sum2[i]);
			printf(" / ");
			for(int i=0;i<=4;i++)
				printf("%d",sum1[i]);
			printf(" = ");	
			printf("%d\n",n);
		}
		memset(sum2,0,sizeof(sum2));
		memset(u,0,sizeof(u));
		return ;
	}
	for(int i=0;i<=9;i++){
		if(vis[i])continue;
		vis[i]=1,sum1[dep]=i;
		dfs(dep+1);
		vis[i]=0,sum1[dep]=0;		
	}
}
signed main(){
	scanf("%d",&n);	
	while(n){
		if(n<=80){
			ans=0;
			memset(vis,0,sizeof(vis));
			memset(sum1,0,sizeof(sum1));
			memset(sum2,0,sizeof(sum2));
			memset(u,0,sizeof(u));
			dfs(0);
		}
		if(ans==0)printf("There are no solutions for %d.\n",n);	
		scanf("%d",&n);	
		if(n)cout<<'\n';		
	}

	return 0;
}
