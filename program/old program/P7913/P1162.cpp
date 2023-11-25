#include <iostream> 
#include <queue>
#include <cstdio>
using namespace std;
int map[310][300],fx[4]={1,-1,0,0},fy[4]={0,0,1,-1};
struct Node
{
	int x,y;
};
queue<Node> que;
int main()
{
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			scanf("%d",&map[i][j]);
		}
	}
	for(int i = 1;i<=n;i++)
	{
		if(map[i][1]!=1)que.push({i,1});
		if(map[1][i]!=1)que.push({1,i});
		if(map[i][n]!=1)que.push({i,n});
		if(map[n][i]!=1)que.push({n,i});
	}
	while(!que.empty())
	{
		map[que.front().x][que.front().y]=3;
		for(int i = 0;i<4;i++)
		{
			int X=que.front().x+fx[i],Y=que.front().y+fy[i];
			if(X<1||Y<1||X>n||Y>n||map[X][Y]==3||map[X][Y]==1)continue;
			que.push({X,Y});
			map[X][Y]=3;
		}
		que.pop();
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			if(map[i][j]==3)
			{
				cout<<0<<" ";
			}
			else if(map[i][j]==0)
			{
				cout<<2<<" ";
			}
			else cout<<1<<" ";
		}
		cout<<endl;
	}
	return 0;
}
