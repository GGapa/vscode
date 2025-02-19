#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n,m,k,x[N],y[N];
unordered_map<int,bool> vis[N];
int main()
{
	freopen("user.out", "r", stdin);
	freopen("checker.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=k;i++) 
	{
		scanf("%d%d",&x[i],&y[i]);
		if(x[i]<1||x[i]>n||y[i]<1||y[i]>m||vis[x[i]][y[i]]) return puts("-1"),0;
		vis[x[i]][y[i]]=true;
	}
	for(int i=1;i<k;i++) for(int j=i+1;j<=k;j++) {
		if(abs(x[i]-x[j])==abs(y[i]-y[j])) return puts("-1"),0;
	}
	puts("Yes");
	return 0;
}