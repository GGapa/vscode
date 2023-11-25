// T353707 『MGOI』Simple Round I | A. 魔法数字
// https://www.luogu.com.cn/problem/T353707?contestId=101050
#include <iostream>
#include <cstdio>
using namespace std;
int n;
int main()
{
    cin >> n;
    int sum = 1;
    for(int m = 0; m <= 32; m += 2)
    {
        if(sum * 4 >= n) {
            cout << m << endl;
            return 0;
        }
        sum *= 4;
    }
    return 0;
}