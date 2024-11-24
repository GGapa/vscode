/*
#include <iostream>//input,output,流
#include<bitset>
#include<stdio.h>//位运算
using namespace std;//标准standard库
int diao()
{
	unsigned a, b;
	scanf_s("%u", &a);
	b = a >> 4;
	b = b & 0x000F;
	cout << bitset<32>(a) << endl;
	cout << bitset<32>(b) << endl;
	printf("\na = %u b = %u ", a, b);
	return 0;
}
int main()
{
	char a = 1, b = 3;
	cout << bitset<8>(a) << endl;
	cout << bitset<8>(b)<<endl;
	cout << bitset<8>(a ^ b)<<endl;
	diao();
	return 0;
}
*/
