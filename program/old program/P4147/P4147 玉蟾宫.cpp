//P4147 Óñó¸¹¬
#include <iostream>
using namespace std;
char map[1001][1001];
int dp[1001][1001],up[1001][1001],l[1001][10001],r[1001][10001];
int main()
{
	
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=m;j++)
		{
			char input;
			cin>>map[i][j];
			up[i][j]=1;
			l[i][j]=r[i][j]=j;
		}
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = 2;j<=m;j++)
		{
			if(map[i][j]=='F'&&map[i][j-1]=='F')
			{
				l[i][j]=l[i][j-1];
			}
		}
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = m-1;j>0;j--)
		{
			if(map[i][j]=='F'&&map[i][j+1]=='F')
			{
				r[i][j]=r[i][j+1];
			}
		}
	}
	int ans=1;
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=m;j++)
		{
			if(i>1&&map[i][j]=='F'&&map[i-1][j]=='F')
			{
				r[i][j]=min(r[i][j],r[i-1][j]);
				l[i][j]=max(l[i][j],l[i-1][j]);
				up[i][j]=up[i-1][j]+1;
			}
			ans=max(ans,(r[i][j]-l[i][j]+1)*up[i][j]);
		}
	}
	int num=0;
	for(int i = 1;i<=n;i++) 
	{
		for(int j = 1;j<=m;j++)
		{
			if(map[i][j]=='F')
			num++;
		}
	}
	if(num!=0)cout<<ans*3<<endl;
	else cout<<0<<endl;
	return 0;
}
