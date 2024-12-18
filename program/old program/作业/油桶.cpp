/*假如你现在是老板，经营一家货运公司，一共有两种货车。
第一种货车跑一趟需要2天，烧 4 桶油，可以创造 1000 的利润。

第二种跑一趟要 15 天，烧 8 桶油，但是可以创造 5000 的利润。

那如果你手上有 500 桶油，应该怎么配比两种货车的货运次数才能在一年内获得最大利润呢?
#include <iostream>
using namespace std;

int main()
{
	int i=0, j=0, q, lirun, max = -1,x=0,y=0;
	for (x = 0; x < (365 / 2); x++)
	{
		for (y = 0; y < (360 / 15); y++)
		{
			if ((x * 4 + y * 8) > 500) continue;
			if ((x * 2 + y * 15) > 365) continue;
			if ((x * 1000 + y * 5000) > max)
			{
				max = (x * 1000 + y * 5000);
				i = x; 
				j = y;
			}
		}
	}
	cout <<i<<" "<<j<<" " <<max<< endl;
	return 0;
}
*/