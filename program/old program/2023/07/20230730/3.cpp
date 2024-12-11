#include <iostream>
#include <vector>

using namespace std;

int can_be_represented(int x, const vector<int>& arr) {
    int y_sum = 0;
    for (int num : arr) {
        y_sum += x / num;
    }
    return y_sum;
}

int count_representable_numbers(int n, int l, int r, const vector<int>& arr) {
    int count = 0;
    for (int x = l; x <= r; ++x) {
        if (can_be_represented(x, arr) == x) {
            count++;
        }
    }
    return count;
}

int main() {
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = count_representable_numbers(n, l, r, arr);
    cout << result << endl;

    return 0;
}
