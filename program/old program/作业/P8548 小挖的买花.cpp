/*
#include <iostream>
using namespace std;
struct fl
{
	int cost, fresh, beautiful;
}flower[505];
long long bag[505][505];
int main()
{
	int n, q,c,f;
	cin >> n >> q;
	for (int i = 0; i < n; i++)cin >> flower[i].cost >> flower[i].fresh >> flower[i].beautiful;
	while (q--)
	{
		cin >> c >> f;
		for (int i = 0; i < n; i++)
		{
			for (int j = c; j >= 0; j--)
			{
				for (int qq = f; qq >= 0; qq--)
				{
					bag[j][qq] = max(bag[j][qq], flower[i].beautiful + bag[j - flower[j].cost][qq - flower[q].fresh]);
				}
			}
		}
		cout << bag[c][f] << endl;
	}
	return 0;
}
*/