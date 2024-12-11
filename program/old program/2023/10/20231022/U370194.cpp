#include <iostream>
#include <map>
using namespace std;

map<int, string> mp;
map<char, int> num;
void init() {
    int it = 0;
    for(char i = 'A'; i <= 'Z'; i++) {
        mp[it] += i;
        num[i] = it;
        it++;
    }
    for(char i = 'B'; i <= 'Z'; i++) {
        for(int j = 'A'; j <= 'Z'; j++){
            mp[it] += i;
            mp[it] += j;
            it++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    char A, B;
    cin >> A >> B;
    cout << mp[num[A] + num[B]] << "\n";
    return 0;
}