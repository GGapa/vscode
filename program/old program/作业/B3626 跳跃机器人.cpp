/*
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
struct robot
{
	int x, cost = 0;
};
queue<robot>bfs;
int map[2000001];
int main()
{
	memset(map, 0, sizeof(map));
	robot temp;
	int n;
	cin >> n;
	temp.x = 1;
	bfs.push({ 1 ,1 });
	while (!bfs.empty()) {
		int X = bfs.front().x - 1, C = bfs.front().cost + 1;
		if (X > 0 && (map[X] == 0 || map[X] > C)) {
			bfs.push({ X,C });
			map[X] = C;
		}
		X = bfs.front().x + 1, C = bfs.front().cost + 1;
		if (X <= n && (map[X] == 0 || map[X] > C)) {
			bfs.push({ X, C });
			map[X] = C;
		}
		X = bfs.front().x * 2, C = bfs.front().cost + 1;
		if (X <= n && (map[X] == 0 || map[X] > C)) {
			bfs.push({ X, C });
			map[X] = C;
		}
		bfs.pop();
	}
	cout << map[n]-1 << endl;
	return 0;
}
*/