/*
#include <iostream>
using namespace std;
constexpr auto maxn = 30;

struct node_
{
	char father, left, right;
};
node_ node[maxn];

void re(char x)
{
	if (node[x - 'a'].left == '*' && node[x - 'a'].right == '*')
		return;
	if (node[x - 'a'].left != '*' && node[x - 'a'].left != 0)
	{
		cout << node[x - 'a'].left;
		re(node[x - 'a'].left);
	}
	if (node[x - 'a'].right != '*' && node[x - 'a'].right != 0)
	{
		cout << node[x - 'a'].right;
		re(node[x - 'a'].right);
	}
}

int main()
{
	int n;
	char ls, start;
	cin >> n;
	cin >> ls;
	start = ls;
	node[ls - 'a'].father = ls;
	cin >> node[ls - 'a'].left >> node[ls - 'a'].right;
	n--;
	while (n--)
	{
		cin >> ls;
		node[ls - 'a'].father = ls;
		cin >> node[ls - 'a'].left >> node[ls - 'a'].right;
	}
	cout << start;
	re(start);
	cout << endl;
	return 0;
}
*/