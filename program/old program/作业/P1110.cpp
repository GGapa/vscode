/*
#include <iostream>
#include <cstring>
using namespace std;

int arr[50001] = { 0 };

struct object
{
	int num[50001] = { 0 };
	int preMin = 99999999;
	int nextMin = 99999999;
};


int main()
{
	string command;
	int n, m;
	cin >> n>>m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		int index, value;
		cin >> command;
		if (command[0] == 'I')
		{
			cin >> index >> value;
		}
		else if (command[4] == 'S')
		{//MIN_SORT_GAP：查询所有元素中最接近的两个元素的差值（绝对值）。

		}
		else
		{//MIN_GAP：查询相邻两个元素的之间差值（绝对值）的最小值。

		}

	}


}
*/