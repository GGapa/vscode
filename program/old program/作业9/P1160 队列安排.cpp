/*
#include <iostream>
#include <list>
using namespace std;

struct d
{
	int xh = 0;
	int pre = 0;
	int next = 0;
};

int n, ls = 0;
//d a[100000];
int main()
{
	cin >> n;
	a[1].xh = 1;
	a[1].pre = 0;
	a[1].next = 2;
	a[0].next = 1;
	for (int j = 2; j <= n; j++)
	{
		int i, k;
		cin >> i >> k;
		//i- ����λ��
		//k= 0 ���   1�ұ�
		//j=ѧ��
		if (k == 0)
		{
			if (a[i + 1].xh == 0)a[i].next = 0;
			a[j].xh = j;   //�Լ���ѧ��
			//a[i].next = j - 1;
			a[a[i].pre].next = j;  //ԭ�е���һ����next
			a[j].next = i;			//�Լ�����һ��
			a[i].pre = j;			//ԭ�е���һ��
		}
		else
		{
			if (a[a[i].next].xh != 0)a[j].next = a[a[i].next].xh;
			a[j].xh = j;

			a[a[i].next].pre = j;

			a[j].pre = i;
			a[i].next = j;
		}
	}


	ls = a[0].next;
	int num = 1, m;
	cin >> m;
	bool bj=false;
	while (true)
	{
		if (bj && a[ls].xh != 0)
		{
			cout << " ";
		}
		if (num > n)break;
		if (a[ls].xh != 0)
			cout << a[ls].xh;
		ls = a[ls].next;
		num++;
		if (a[ls].xh != 0)bj = true;
	}
	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		a[x].xh = 0;
	}
	while (true)
	{
		if (bj&&a[ls].xh!=0)
		{
			cout << " ";
		}
		if (num > n)break;
		if (a[ls].xh != 0)
			cout << a[ls].xh;
		ls = a[ls].next;
		num++;
		if(a[ls].xh != 0)bj = true;
	}
	cout << endl;
	return 0;
}
*/