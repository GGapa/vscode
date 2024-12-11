/*
T366243 Khronostasis Katharsis
https://www.luogu.com.cn/problem/T366243?contestId=124047
*/

#include <iostream>
using namespace std;
const int maxn = 1e5 + 5;

int n, T;
int v[maxn], t[maxn], high[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> T;
    for(int i = 1; i <= n; i++) {
        cin >> v[i] >> t[i];
        high[i] = max(T - t[i], 0) * v[i];
    }
    int minHigh = -1, index;
    for(int i = 1; i <= n; i++) {
        if(high[i] > minHigh) {
            minHigh = high[i];
            index = i;
        }
    }
    cout << index << endl;
}