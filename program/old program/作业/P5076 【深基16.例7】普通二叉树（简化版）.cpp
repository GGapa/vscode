/*
#include <iostream>
#include <map>
using namespace std;
#define maxn 10001
struct node_
{
	int value = 0, left = 0, right = 0, size = 0, cnt = 0, father = 0, himself = 0;
};

node_ node[maxn];
int start = -1, xmax = -2147483647, xmin = 2147483647, ranknum = 1, findnum = 1, num = 1;

void add(int x, int y)
{
	if (y == -1)
	{
		node[num].value = x;
		node[num].father = y;
		node[num].size++;
		node[num].cnt++;
		node[num].himself = num;
		start = num;
		return;
	}
	node[y].size += 1;
 	if (x == node[y].value)
	{
		node[y].cnt++;
		return;
	}
	if (x > node[y].value)
	{
		if (node[node[y].right].value == 0||node[y].right==0)
		{
			node[y].right = ++num;
			node[num].value = x;
			node[num].father = y;
			node[num].size++;
			node[num].cnt++;
			node[num].himself = num;
			return;
		}
		else
			add(x, node[y].right);
	}
	else if (x < node[y].value)
	{
		if (node[node[y].left].value == 0||node[y].left==0)
		{
			node[y].left = ++num;
			node[num].value = x;
			node[num].father = y;
			node[num].size++;
			node[num].cnt++;
			node[num].himself = num;
			return;
		}
		else
			add(x, node[y].left);
	}
}
void finds(int x, int y)
{
	if (xmin != 2147483647)
		return;
	if (node[node[y].left].value == 0 && node[node[y].right].value == 0)
		return;
	else if (x > node[y].value)
	{
		if (node[node[y].right].value != 0)
			finds(x, node[y].right);
		else
			return;
	}
	else if (x < node[y].value)
	{
		if (node[node[y].left].value != 0)
			finds(x, node[y].left);
		else
			return;
	}
	else if (x == node[y].value)
	{
		if (node[node[y].right].value == 0)
			xmin = node[node[y].left].value;
		else if (node[node[y].left].value == 0)
			xmin = node[node[y].right].value;
		else
			xmin = max(node[ node[y].left].value, node[y].right);
	}
}
void findb(int x, int y)
{
	if (xmax != -2147483647)
		return;
	if (node[node[y].left].value == 0 && node[node[y].right].value == 0)
	{
		if (x > node[y].value)
			xmin = node[y].value;
	}
	else if (node[node[y].left].value == x || node[node[y].right].value == x)
		xmax = node[y].value;
	else if (x > node[y].value)
	{
		if (node[node[y].right].value != 0)
			finds(x, node[y].right);
		else
			return;
	}
	else if (x < node[y].value)
	{
		if (node[node[y].left].value != 0)
			finds(x, node[y].left);
		else
			return;
	}
}
void rankx(int x, int y, int rank)
{
	if (x == 0)
	{
		ranknum = 0;
		return;
	}
	if (node[node[y].left].value == 0 && node[node[y].right].value == 0)
		return;
	if (node[y].value == x)
	{
		ranknum = rank+1;
		return;
	}
	if (x > node[y].value)
	{
		rankx(x, node[y].right, node[node[y].left].size + node[y].cnt);
	}
	if (x < node[y].value)
	{
		rankx(x, node[y].left, node[node[node[y].left].left].size);
	}
}
void findrank(int x, int y)
{
	if (node[node[y].left].value == 0 && node[node[y].right].value == 0)
		return;
	if (node[node[y].left].size + node[y].cnt > x)
	{
		if (node[node[y].left].value != 0 && node[y].left != y)
			findrank(x - node[y].cnt, node[y].left);
		else
			findnum = node[y].value;
	}
	if (node[node[y].left].size + node[y].cnt < x)
	{
		if (node[node[y].right].value != 0 && node[y].right!=y)
			findrank(x - (node[node[y].left].size + node[y].cnt), node[y].right);
		else
			findnum = node[y].value;
	}
	if (node[node[y].left].size + node[y].cnt == x)
	{
		findnum = node[y].value;
		return;
	}
}
int main()
{
	int n, x, y;
	bool bj = true;
	cin >> n;
	while (n--)
	{
		cin >> x >> y;
		if (x == 5)
		{
			add(y, start);
			//node[y].cnt++;
		}
		if (x == 4)
		{
			xmin = 2147483647;
			finds(y, start);
			cout << xmin << endl;
		}
		if (x == 3)
		{
			xmax = -2147483647;
			findb(y, start);
			cout << xmax << endl;
		}
		if (x == 2)
		{
			findrank(y, start);
			cout << findnum << endl;
		}
		if (x == 1)
		{
			ranknum = 1;
			rankx(y, start, node[start].size-1);
			cout << ranknum << endl;
		}
	}
	return 0;
}
*/