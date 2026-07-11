#include<iostream>
using namespace std;

const int N = 1e6 + 5;
int a[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
    int i;
    cin >> i;
    for (i;i;i = a[i]) cout << i << ' '; // 神奇
    cout << endl;
    return 0;
}