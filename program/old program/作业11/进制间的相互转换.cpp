/*
#include <cmath>
#include <string>
#include <iostream>
using namespace std;
char a[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
string z = "0123456789ABCDEF";
int main()
{
	int b = 150;
	string n, x;
	//ʮ����ת��������

	while (b != 0)
	{
		n += char(b % 2 + 48);
		b /= 2;
	}
	for (int i = n.length(); i >= 0; i--)
		cout << n[i];
	cout << endl;
	//������ת��ʮ����
	n = "10010110";
	b = 0;
	for (int i = 7; i >= 0; i--)
	{
		b += (n[7 - i] - '0') * pow(2, i);
	}
	cout << b << endl;
	//ʮ����ת��ʮ������
	b = 255;
	n = "";
	while (b != 0)
	{
		if (b % 16 <= 10)
			n += char(b % 16 + 48);
		else
			n += char(b % 16 + 55);
		b /= 16;
	}
	for (int i = n.length(); i >= 0; i--)
		cout << n[i];
	cout << endl;
	//ʮ������תʮ����
	n = "96";
	b = 0;
	for (int i = 0; i < n.length(); i++)
	{
		b += z.find(n[i]) * pow(16, n.length() - i - 1);
	}
	cout << b << endl;
	return 0;
}
*/