/*
Stacks of Flapjacks
https://vjudge.csgrandeur.cn/contest/584212#problem/E
2023-10-04
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> a, b;

bool input(string s) {
    a.clear(); b.clear();    
    int len = s.length();
    int sum = 0;
    for(int i = 0; i < len; i++) {
        if(i == len - 1) {
            a.push_back(sum * 10 + (s[i] - '0'));
            break;
        }
        if(s[i] == ' ') {
            a.push_back(sum);
            sum = 0;
        }
        else sum = sum * 10 + (s[i] - '0');
    }
    b = a;
    sort(b.begin(), b.end());
    return true;
}

void flip2(int n) {
   int left = 0, right = n;
    while(left < right)
        swap(a[left++], a[right--]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    while(getline(cin, s)) {
        input(s);
        for(auto i : a) cout << i << " ";
        cout << "\n";
        int n = a.size() - 1;
        
        for(int i = n; i >= 0; i--) {
            if(a[i] == b[i]) continue;  //归位了就跳过
            for(int j = 1; j < i; j++) {
                if(a[j] == b[i]) {
                    flip2(j); //把他放到最顶上
                    cout << n - j + 1 << " ";
                }
            }
            flip2(i);  //放回去
            cout << n - i + 1 << " ";
        }
        cout << "0\n";
    }
    return 0;
}