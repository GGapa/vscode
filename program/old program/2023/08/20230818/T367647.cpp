/*
https://www.luogu.com.cn/problem/T367647?contestId=126183
T367647 Sequence
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;

int n;
int A[maxn], b[maxn], a[maxn], valh[maxn], valq[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n + 1; i++) {
        cin >> A[i];
        a[i] = A[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    sort(a + 1, a + 1 + n + 1, greater<int>());
    sort(b + 1, b + 1 + n, greater<int>());
    for(int i = 1; i <= n; i++) {
        valh[i] = max(a[i + 1] - b[i], 0);
        valq[i] = max(a[i] - b[i], 0);
        valq[i] = max(valq[i - 1], valq[i]);
    }
    for(int i = n; i >= 1; i--) {
        valh[i] = max(valh[i], valh[i + 1]);
    }
    for(int i = 1; i <= n + 1; i++) {
        int left = 1, right = n + 1;
        int index;
        while(left < right) {
            int mid = (left + right) >> 1;
            if(A[i] < a[mid]) left = mid + 1;
            if(A[i] >= a[mid]) right = mid;
        }
        index = left;
        cout << max(valq[index - 1], valh[index]) << " \n"[i == n + 1];
    }
    return 0;
}
/*
6 3 3 1
4 3 2 1

*/