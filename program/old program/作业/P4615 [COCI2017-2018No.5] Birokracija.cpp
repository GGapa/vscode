/*
#include <iostream>
#include <vector>
using namespace std;
#define maxn 200001
struct no
{
	long long father = 0, num = 1;
	vector<int> sons;
	long long sonsum = 1;
}person[maxn];
bool used[maxn] = { false };
void fs(int f)
{

}
int main()
{
	int n;
	cin >> n;
	person[1].father = 1;
	for (int i = 2; i <= n; i++)
	{
		int input;
		cin >> input;
		person[i].father = input;
		person[input].sons.push_back(i);
	}
	for (int i = n; i >= 1; i--)
	{
		//person[i].sonsum = person[i].sons.size();
		for (int j = 0; j < person[i].sons.size(); j++)
		{
			person[i].num += person[person[i].sons[j]].num;
			person[i].num += person[person[i].sons[j]].sonsum;
			person[i].sonsum += person[person[i].sons[j]].sonsum;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << person[i].num << " ";
	}
	return 0;
}
*/