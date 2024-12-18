/*
#include <iostream>
using namespace std;

int main()
{
	int all = 0,all_;
	char a[14];
	scanf_s("%s", a, 14);
	all = ((int(a[0])-48) * 1 +
		(int(a[2])-48) * 2 +
		(int(a[3])-48) * 3 +
		(int(a[4])-48) * 4 +
		(int(a[6])-48) * 5 +
		(int(a[7])-48) * 6 +
		(int(a[8])-48) * 7 +
		(int(a[9])-48) * 8 +
		(int(a[10])-48) * 9) % 11;
	if (a[12] == 'X' && all == 10 ) cout << "Right";
	else if(int(a[12])-48==all) cout << "Right";
	else if (all == 10) cout << a[0] << a[1] << a[2] << a[3] << a[4]<< a[5] << a[6]<<a[7] << a[8] << a[9] << a[10]<<a[11] << 'X' << endl;
	else cout << a[0] << a[1] << a[2] << a[3] << a[4] << a[5] << a[6]<<a[7] << a[8] << a[9] << a[10] <<a[11]<< all << endl;

}
*/