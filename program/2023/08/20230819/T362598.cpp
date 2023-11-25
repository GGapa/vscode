/*
T362598 Glaciaxion
https://www.luogu.com.cn/problem/T362598?contestId=124047
*/

#include <iostream>
#include <vector>
using namespace std;
#define F "No solution"

int n, m;
char info[1000005];
vector<int> ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin >> info;
    int now = 1;
    for(int i = 0; i < m; i++) {
        if(info[i] == 'N') {
            ans.push_back(now++);
        }
        else {
            if(now == 1) {
                cout << F << endl;
                return 0;
            }
            ans.push_back(1);
        }
    }
    if(now > n + 1) {
        cout << F << endl;
        return 0;
    }
    for(int i = 0; i < ans.size(); i++)     {
        cout << ans[i] << " ";
    }
    return 0;
}