/*
#include <iostream>
using namespace std;
constexpr auto maxn = 1000005;
struct node_
{
	int father, left, right;
};
node_ node[maxn];
int ans=0,deep=1;
void re(int x,int y)
{
	if (node[x].left == 0 && node[x].right == 0)
		return;
	y++;
	ans = max(ans, y);
	re(node[x].left,y);
	re(node[x].right,y);

		
}t
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> node[i].left >> node[i].right;
		node[i].father = i;
	}
	re(1,1);
	cout << ans << endl;
	return 0;
}
*/