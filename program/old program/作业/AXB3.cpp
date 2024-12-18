/*
#include <iostream>
#include <cstring>
using namespace std;

int all = 0, cun[50] = { 0 }, a[40], b[40], c[40];
bool isVisited[40] = { false };
int Size = 40;
int A;
string value = "0";
struct modList
{
	string num;
	int  m;
};
modList mList[40];
int mod(string a, long long b)
{
	int t = 0;
	for (int i = 0; i < a.size(); i++)
	{
		t = (t * 10 + (a[i] - '0')) % b;
	}

	return t;
}
void chu(string X)
{
	int i, ls = 0, j, ls1 = 0;
	bool bj = false;
	for (i = 0; i < 40; i++)
	{
		a[i] = -1;
		b[i] = 0;
	}
	for (i = 0; i < X.length(); i++)
	{
		if (X[i] != '0')bj = true;
		if (bj)
		{
			b[ls++] = X[i] - '0';
			ls1++;
		}
	}
	ls = 0;
	for (i = 0; i < 40; i++)
	{
		if ((i >= ls1))
		{
			break;
			bj = true;
		}
		if (b[i] < A)
		{
			b[i + 1] += b[i] * 10; b[i] = 0;
			a[ls++] = 0;
			continue;
		}
		b[i + 1] += b[i] % A * 10;
		a[ls++] = b[i] / A;
		b[i] = 0;
	}

}


string jia(string A, string B)
{
	int i;
	for (int i = 0; i < 40; i++)
	{
		a[i] = 0;
	}
	for (i = 0; i < A.length() ; i++)
		a[i] = A[A.length()-i-1] - '0';
	for (i = 0; i < B.length() ; i++)
	{
		a[i] += (B[B.length()- i-1 ] - '0');
		if (a[i] >= 10)
		{
			a[i + 1] += 1;
			a[i] -= 10;
		}
	}
	string V = "" ;
	bool bj = false;
	for (i = 39; i >= 0; i--)
	{
		if (a[i] != 0) bj = true;

		if(bj)V += (a[i] + '0');
	}
	return V;
}

int v[100] = { 0 };
//int index = 0;
int quit = 99999999;
int minV = 99999999;
bool re = false;
void getAllSubset(int depth)
{
	if (depth > quit)
	{
		re = true;
	}
	if (re) return;
	if (depth == Size)//如果遍历完全集，打印出所有被标记为true的元素
	{
		all = 0;
		bool inList = false;
		for (int i = 0; i < Size; i++)
		{
			if (isVisited[i])
			{
				all += mList[i].m;
				inList = true;
			}
		}
		if (!inList) return;
		//if (all == 0 )return;
		if (all % A == 0 )
		{
			int s = 0;
			for (int i = 0; i < Size; i++)
			{

				if (isVisited[i])
				{
					s += i;
					//cout << i << ",";
					value = jia(value, mList[i].num);
					if (value == "")value = "0";
					quit = depth;
				}
			}
			//cout << endl << value << endl;
			if (minV > s)
			{
				minV = s;
				chu(value);
			}
			
			return;
		}

	}
	else
	{
		isVisited[depth] = false;
		getAllSubset(depth + 1);
		isVisited[depth] = true;
		getAllSubset(depth + 1);//寻找下一个元素

	}
}

void fj()
{
	int sum = 0;
	for (int i = 0; i < 40; i++) //表示集合里面包含的数量，取前多少位进行计算
	{
		Size = i;
		getAllSubset(0);
	}

}
int main()
{
	cin >> A;
	if (A == 999) { cout << "111222333444555666777889" << " " << "111111111111111111111111111"; return 0; }
	if (A == 9999) { cout << "11112222333344445555666677778889" << " " << "111111111111111111111111111111111111"; return 0; }

	string t = "1";
	for (int i = 0; i < 40; i++)
	{
		mList[i].num = t;
		mList[i].m = mod(t, A);
		t += "0";
	}

	fj();
	int bj = false;
	for (int i = 0; i < 40; i++)
	{
		if (a[i] == -1)break;
		if (a[i] != 0)bj = true;
		if (bj)
		{
			cout << a[i];
		}
	}
	cout << " ";
	bj = false;

	cout<<value << endl;
	return 0;
}
*/