//#include <iostream>
//#include <cstring>
//using namespace std;
//int len = 0;
//string a;
//void jy()
//{
//	string ls = "", jia = "", ls1 = "";
//	int start=-1, end=-1, xun;
//	len = a.length();
//	for (int i = 0; i < len; i++)
//	{
//		if (a[i] == '[')
//		{
//			start = i;
//		}
//		if (a[i] == ']')
//		{
//			end = i;
//			break;
//		}
//	}
//	if (start == -1)return;
//	for (int i = 0; i < start; i++)
//		ls += a[i];
//	for (int i = start+2; i < end; i++)
//		if (48 > a[i] || a[i] > 58)jia += a[i];
//	if (48 <= a[start + 2] && a[start + 2] <= 58)
//		xun = (a[start + 1]-48) * 10 + a[start + 2]-48;
//	else
//		xun = a[start + 1]-48;
//	for (int i = 1; i <= xun; i++)
//		ls1 += jia;
//	ls += ls1;
//	for (int i = end+1; i < len; i++)
//		ls += a[i];
//	a = "";
//	a += ls;
//	ls = "";
//	len = a.length();
//	for (int i = 0; i < len; i++)
//	{
//		if (a[i] == '[')
//		{
//			start = i;
//		}
//		if (a[i] == ']')
//		{
//			end = i;
//			jy();
//		}
//	}
//	return ;
//}
//
//
//int main()
//{
//	cin >> a;
//	len = a.length();
//	jy();
//	cout << a << endl;
//}