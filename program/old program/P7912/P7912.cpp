
#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;
#define maxn 200005
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch>'9') {
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}

int n, sum = 0;
struct l
{
	int vaule, num;
};
int x[maxn];
queue<l>a, b;
int main()
{
	l temp;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		temp.vaule = read();
		temp.num = i;
		a.push(temp);
	}
	temp.vaule = temp.num = INT_MIN;
	a.push(temp);
	while (a.size() != 1)
	{
		int f=INT_MIN;
		int len = a.size();
		for (int i = 0; i < len; i++)
		{
			if (a.front().vaule == INT_MIN)
			{
				a.push(a.front());
				a.pop();
				break;
			}
			if (a.front().vaule != f)
			{
				x[sum++] = a.front().num;
			}
			else
				a.push(a.front());
			f = a.front().vaule;
			a.pop();
		}
		for (int i = 0; i < sum; i++)
		{
			printf("%d ", x[i]);
			x[i] = 0;
		}
		printf("\r\n");
		sum = 0;
	}
	return 0;
}
