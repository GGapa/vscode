//https://www.luogu.com.cn/problem/T364884?contestId=121028
//T364884 小粉兔喜欢下象棋吗
#include <iostream>
#include <cstdio>
using namespace std;
int sx, sy, cx, cy, mx, my;
int fx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int fy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
bool check(int x,int y) {
    int sum = 0;
    for(int i = 0; i < 8; i++) {
        int nx = fx[i] + x;
        int ny = fy[i] + y;
        if((nx == sx && ny == sy) || (nx == cx && ny == cy)) sum++;
        if(sum == 2) {
            return true;
        }
    }
    return false;
}
int main() {    
    cin >> sx >> sy >> cx >> cy >> mx >> my;
    for(int i = 0; i < 8; i++) {
        int nx = fx[i] + mx;
        int ny = fy[i] + my;
        if(check(nx, ny)) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}