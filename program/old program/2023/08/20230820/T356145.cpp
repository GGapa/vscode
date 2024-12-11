/*
T356145 「TAOI-2」核心共振
https://www.luogu.com.cn/problem/T356145?contestId=122483
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
const int maxn = 1e5 + 5;
#define int long long

int used[maxn], a[maxn];
int T, n, p;
int it = 1;
map<int, queue<int> > numbers;

signed main() {
    cin >> T;
    while(T--) {
        cin >> n >> p;
        for(int i = 1; i <= n; i++) {
            int Mod = i % p;
            numbers[Mod].push(i);
        }
        for(int i = 1; i <= n; i++) {
            int M = i % p;
            if(numbers[M].empty()) continue;
            while(!numbers[M].empty()) {
                cout << numbers[M].front() << " ";
                numbers[M].pop();
                M = p - M;
            }
        }
        cout << endl;
    }
    return 0;
}
