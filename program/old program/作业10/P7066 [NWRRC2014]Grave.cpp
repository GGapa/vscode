/*
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	int x1, y1, x2, y2, w, h, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;
	cin >> w >> h;
	string bj = "No";
	if (abs(x2 - x1) >= w && abs(y3 - y1) >= h)
		bj = "Yes";
	else if (abs(x3 - x1) >= w && abs(y2 - y1) >= h)
		bj = "Yes";
	else if (abs(x2 - x1) >= w && abs(y2 - y4) >= h)
		bj = "Yes";
	else if (abs(x2 - x4) >= w && abs(y2 - y1) >= h)
		bj = "Yes";
	cout << bj << endl;
	return 0;
}
*/