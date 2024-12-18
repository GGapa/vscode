#include <iostream>
#include <vector>
using namespace std;

int n;
const int maxn = 1e6 + 5;
int a[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    bool flag1 = true, flag2 = true;
    int ans1, ans2; ans1 = ans2 = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i-1] < a[i] && flag1) {
            flag1 = false;
            ans1++;
        }
        else {
            flag1 = true;
        }
        if(a[i-1] > a[i] && flag2) {
            flag2 = false;
            ans2++;
        }
        else {
            flag2 = true;
        }
    }
    cout << min(ans1, ans2) << "\n";
    return 0;
}