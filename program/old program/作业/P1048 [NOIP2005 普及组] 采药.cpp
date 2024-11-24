//
//#include <iostream>
//using namespace std;
//int bag[200][2000] = { 0 };
//int main()
//{
//	int t, m,a[200][2]/*时间*//*价值*/,tall=0/*时间和*/, mall = 0/*价值和*/,tmin=0/*最小时间*/,mmax=0/*最大价值*/,start=1;
//	cin >> t >> m;
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < 2; j++)
//		{
//			cin >> a[i][j];
//		}
//	}
//	for (int i = 0; i < 1000; i++)bag[0][i] = 0;
//	for (int i = 0; i < 100; i++)bag[i][0] = 0;
//	for (int i = 1; i <= m;i++)//物品个数
//	{
//		for (int j = 1; j <= t; j++)//时间不超过
//		{
//			if (a[i - 1][0] > j)
//			{
//				bag[i][j] = bag[i - 1][j];
//			}
//			else
//			{
//				bag[i][j] = max(bag[i - 1][j], a[i - 1][1] + bag[i - 1][j - a[i - 1][0]]);
//			}
//		}
//	}
//	cout << bag[m][t] << endl;
//	return 0;
//}
//