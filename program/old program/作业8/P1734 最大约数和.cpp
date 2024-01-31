//#include <iostream>
//using namespace std;
//int a[1000][1000] = { 0 }, y[1000];
//int main()
//{
//	int s;
//	cin >> s;
//
//	for (int i = 1; i <= s; i++)
//	{
//		for (int j = 1; j < i; j++)
//		{
//			if (i % j == 0)
//				y[i] += j;
//		}
//	}
//	for (int i = 1; i <= s; i++)
//	{
//		for (int j = 1; j <= s; j++)
//		{
//			if (i > j)
//			{
//				a[i][j] = a[i - 1][j];
//			}
//			else
//			{
//				a[i][j] = max(a[i - 1][j], y[i] + a[i - 1][j-i]);
//			}
//		}
//	}
//	cout << a[s][s] << endl;
//	return 0;
//}