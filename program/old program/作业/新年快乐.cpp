/*
#include <iostream>
using namespace std;

int fu()
{
	cout <<
		"    @      @@@@@@\r\n"
		"   @@@      @@@@\r\n"
		"    @       @  @\r\n"
		"   @@@      @@@@\r\n"
		"  @ @ @   @@@@@@@\r\n"
		"    @  @  @  @  @\r\n"
		"    @     @@@@@@@\r\n"
		"    @     @  @  @\r\n"
		"    @     @@@@@@@\r\n";
	return 0;
}
int kuaile()
{
	cout <<
		"������������������������������������������������\r\n"
		" �ЩةЩ������񩤩Щ����������੤����������ȡ�\r\n"
		" �ةЩة��С������੤�����򡡩��������𩸩Щ���\r\n"
		" ���੤��������������  �������ة��ء������੤��\r\n"
		//" �񩦡𩦩����ة��੤�������𡡡��񡡣���������\r\n";
		"������������������������������������������������\r\n";
	cout << endl;
	return 0;
}
int color()
{
	system("color 0F");
	system("color 1F");
	system("color 2F");
	system("color 3F");
	system("color 4F");
	system("color 5F");
	system("color 6F");
	system("color 7F");
	system("color 8F");
	system("color 9F");
	system("color 0F");
	return 0;
}


int main()
{
	int i,num=0;
	cin >> i;
	for (i = 1; i <= 1000; i++)
		cout << "�������"<<" ";
	system("color 0F");
	for (int j = 0; j < 10; j++)
	{
		cout << "ף��ʦ������֣�" << endl;
		for (i = 1; i <= 1000; i++)
			cout << "�������" << " ";
		cout << endl;
	}
	system("color 1F");
	for (i = 0; i <= 1000; i++)
	{
		for (int j = 0; j < i; j++)
			cout << " ";
		cout << "�������" << endl;
		if (i == 200)
		{
			i = 0;
			num++;
		}
		if (num == 10)break;
	}
	system("color 2F");
	num = 0;
	for (i = 200; i >= -1; i--)
	{
		for (int j = i; j > 0; j--)
			cout << " ";
		cout << "�������" << endl;
		if (i == 0)
		{
			i = 200;
			num++;
		}
		if (num == 10)break;
	}
	num = 0;
	system("color 3F");
	for (i = 200; i >= -1; i--)
	{
		for (int j = i; j > 0; j--)
			cout << " ";
		fu();
		if (i == 0)
		{
			i = 200;
			num++;
		}
		if (num == 10)break;
	}
	system("color 4F");
	for (i = 0; i < 9; i++)
	{
		color();
		if (i == 0)cout << "ף";
		if (i == 1)cout << "��";
		if (i == 2)cout << "ʦ";
		if (i == 3)cout << "��";
		if (i == 4)cout << "��";
		if (i == 5)cout << "��";
		if (i == 6)cout << "��";
		if (i == 7)cout << "��";
	}
	cout << endl;
	system("color 0F");
	cout << "��л���ܹ����������Ƶ��ף��������֣�����" << endl;
	cout << "��л���ܹ����������Ƶ��ף��������֣�����" << endl;
	cout << "��л���ܹ����������Ƶ��ף��������֣�����" << endl;
	for (i = 0l;i <= 100000000; i++)
		if (i > 99999990)color();
	return 0;
}*/