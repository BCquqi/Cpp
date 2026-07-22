#include<iostream>
using namespace std;

int a[10] = {6,2,5,5,4,5,6,3,7,6};

int calc(int num) {
    if (num == 0) return 6;
    int ret = 0;
    while (num)
        ret += a[num % 10],num /= 10;
    return ret;
}

int main() {
    int n,ans = 0;
    cin >> n;
    for (int i = 0;i <= 1111;i++)
        for (int j = 0;j <= 1111;j++)
            if (calc(i) + calc(j) + calc(i + j) + 4 == n) ans++;
    cout << ans << endl;
    return 0;
}