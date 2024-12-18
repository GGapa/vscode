/*
T362604 Horizon Blue
https://www.luogu.com.cn/problem/T362604?contestId=124047
*/

#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int n;
map<int, map<int, int> > linesmall;
map<int, int> linebig;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int sum = 0;
    while(n--) {
        int cz;
        cin >> cz;
        int k, b;
        cin >> k >> b;
        if(cz == 1) {
            linesmall[k][b]++;
            sum++;
            linebig[k]++;
        }
        if(cz == 2) {
            cout << sum - linebig[k] << '\n';
        }
        if(cz == 3) {
            sum = linebig[k] - linesmall[k][b];
            map<int ,int> tmp;
            linesmall[k][b] = 0;
            if(abs(k) <= 50)tmp = linesmall[k];
            linesmall.clear();
            linebig.clear();
            linebig[k] = sum;
            linesmall[k] = tmp;
            tmp.clear();
        }
    }
    return 0;
}