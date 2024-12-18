#include <iostream>
using namespace std;

int N, M, P, Q, a[10000], x, y, ans = 0, ls = 0, A, B;
bool start = false;

int find(int x)
{
	if (a[x] == x)
	{
		return x;
	}
	return a[x] = find(a[x]);
}
void add(int x, int y)
{
	if (find(x) == 1)
	{
		int aaa = 1;
	}
	a[find(x)] = find(y);
}

int main()
{
	A = B = 0;
	cin >> N >> M >> P >> Q;
	for (int i = 1; i < 10000; i++)
	{
		a[i] = i;
	}
	for (int i = 0; i < P; i++)
	{
		cin >> x >> y;
		if (y > x)swap(x, y);
		add(x, y);
	}
	ls = 1; A = 0;
	for (int i = 1; i <= N; i++)
	{
		if (find(a[i]) == find(1))
		{
			A++;
			//break;
		}
	}
	for (int i = 1; i < 10000; i++)
	{
		a[i] = i;
	}
	for (int i = 0; i < Q; i++)
	{
		cin >> x >> y;
		x *= -1; y *= -1;
		if (y > x)swap(x, y);
		add(x, y);
	}
	ls = 1; B = 0;
	for (int i = 1; i <= M; i++)
	{
		if (find(a[i]) == find(1))
		{
			B++;
			//break;
		}
	}
	cout << min(A, B) << endl;
	return 0;
}