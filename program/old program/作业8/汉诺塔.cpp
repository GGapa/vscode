/*
using namespace std;
#include <iostream>
#include <cstdio>

void move(int n, char from, char buffer, char to) {
    if (n == 1) {
        cout << from << " To " << to<<endl;
    }
    else {
        move(n - 1, from, to, buffer);
        
        cout << from << " To " << to << endl;
        
        move(n - 1, buffer, from, to);
    }
}
int main()
{
    int a;
    cin >> a;
    move(a, 'A', 'B', 'C');
    return 0;
}
*/