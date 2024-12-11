#include <iostream>
#include <cmath>
#include <map>
using namespace std;

string s1, s2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s1 >> s2;
    if(abs(s1[0] - s1[1]) == abs(s2[0] - s2[1]) || 5 - abs(s1[0] - s1[1]) == abs(s2[0] - s2[1]) || abs(s1[0] - s1[1]) == 5 - abs(s2[0] - s2[1]) || 5 - abs(s1[0] - s1[1]) == 5 - abs(s2[0] - s2[1])) cout << "Yes";
    else cout << "No";
    return 0;
}

