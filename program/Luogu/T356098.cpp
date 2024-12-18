/*
T356098 「TAOI-2」Break Through the Barrier
https://www.luogu.com.cn/problem/T356098?contestId=122483
*/
#include <iostream>
#include <cstring>
#include <set>
#include <map>
using namespace std;

int T, n;
string s1, s2 = "BTTB";
int Next[10];

int main() {
    cin >> T;
    while(T--) {
        cin >> n;
        cin >> s1;
        s1.insert(0, " ");
        int l , r, len = 0, sum = 0, t;
        bool fi = true;
        for(int i = 1; i <= n; i++) {
            if(s1[i] == 'T') {
                if(fi) t = i, fi = false;
                sum++;
            }
            else {
                
                sum = 0;
                fi = true;
            }
            if(sum > len) {
                len = sum;
                l = t;
                r = i;
            }
        }
        cout << l << " " << r << endl;
    }
    return 0;
}