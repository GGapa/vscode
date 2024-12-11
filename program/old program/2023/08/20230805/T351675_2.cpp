//T351675 「RiOI-2」weight
//https://www.luogu.com.cn/problem/T351675?contestId=122184

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

vector <int> vec;
int n, q;

int main() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        for(int j = 1, x; j <= n; j++) {
            cin >> x;
            vec.push_back(x);
        }
    sort(vec.begin(), vec.end());
    vec.push_back(INT_MAX);
    while(q--) {
        int tmp;
        cin >> tmp;
        int left = 0, right = vec.size();
        while(left < right) {
            int mid = (left + right) >> 1;
            if(vec[mid] < tmp) {
                left = mid + 1;
            }
            if(vec[mid] >= tmp){
                right = mid;
            }
        }
        int len = vec.size() - 1;
        cout << min(n, len - left) << endl;
    }
    return 0;
}