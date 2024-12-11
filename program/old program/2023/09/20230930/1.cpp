/*
author:GGapa
2023/9/30
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define double long double

double a, b, c, d;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> c >> d;
    cout << fixed << setprecision(2);
    double mid = (a + b) / 2;
    if(mid >= b) cout << b - a << endl;
    else if(mid <= c) cout << d - c << endl;
    else cout << mid - a << endl;
    return 0;
}