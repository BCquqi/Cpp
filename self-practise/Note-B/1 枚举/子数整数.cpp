#include<iostream>
using namespace std;

int main() {
    int k;
    bool flag = false;
    cin >> k;
    for (int i = 10000;i <= 30000;i++) {
        int a = i / 100, b = i % 10000 / 10, c = i % 1000;
        if (a % k == 0 && b % k == 0 && c % k == 0) {
            flag = true;
            cout << i << endl;
        }
    }
    if (!flag) cout << "No" << endl;
    return 0;
}