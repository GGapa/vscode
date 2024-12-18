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
		"………………………………………………………………\r\n"
		" ┬┴┬┌─　●─┬─　　│─┼─┐　●├─┤○\r\n"
		" ┴┬┴├┬　┌─┼─　│◎　│　│　○└┬┘●\r\n"
		" ─┼─││　│　│　  ││─┴─┴　──┼──\r\n"
		//" ●│○││　┴─┼─　　│○　　●　／　│　＼\r\n";
		"………………………………………………………………\r\n";
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
		cout << "新年快乐"<<" ";
	system("color 0F");
	for (int j = 0; j < 10; j++)
	{
		cout << "祝老师新年快乐！" << endl;
		for (i = 1; i <= 1000; i++)
			cout << "新年快乐" << " ";
		cout << endl;
	}
	system("color 1F");
	for (i = 0; i <= 1000; i++)
	{
		for (int j = 0; j < i; j++)
			cout << " ";
		cout << "新年快乐" << endl;
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
		cout << "新年快乐" << endl;
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
		if (i == 0)cout << "祝";
		if (i == 1)cout << "老";
		if (i == 2)cout << "师";
		if (i == 3)cout << "新";
		if (i == 4)cout << "年";
		if (i == 5)cout << "快";
		if (i == 6)cout << "乐";
		if (i == 7)cout << "！";
	}
	cout << endl;
	system("color 0F");
	cout << "感谢你能够看完这个视频，祝你新年快乐！！！" << endl;
	cout << "感谢你能够看完这个视频，祝你新年快乐！！！" << endl;
	cout << "感谢你能够看完这个视频，祝你新年快乐！！！" << endl;
	for (i = 0l;i <= 100000000; i++)
		if (i > 99999990)color();
	return 0;
}*/