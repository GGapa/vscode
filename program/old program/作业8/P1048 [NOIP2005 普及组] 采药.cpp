//
//#include <iostream>
//using namespace std;
//int bag[200][2000] = { 0 };
//int main()
//{
//	int t, m,a[200][2]/*ʱ��*//*��ֵ*/,tall=0/*ʱ���*/, mall = 0/*��ֵ��*/,tmin=0/*��Сʱ��*/,mmax=0/*����ֵ*/,start=1;
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
//	for (int i = 1; i <= m;i++)//��Ʒ����
//	{
//		for (int j = 1; j <= t; j++)//ʱ�䲻����
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