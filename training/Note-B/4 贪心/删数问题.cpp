#include<iostream>
#include<algorithm>
using namespace std;

const int N = 255;
int a[N];

int main() {
    string n;
    int k;
    cin >> n >> k;
    int len = n.size();
    n = '?' + n;
    for (int i = 1;i <= len;i++) a[i] = n[i] - '0';
    int num = len - k,cnt = 0,start = 1,pos = 0;
    bool flag = false; // 控制前导 0 输出
    while (cnt < num) {
        pos = start;
        for (int i = start;i <= start + k;i++)
            if (a[pos] > a[i]) pos = i;
        if (a[pos] != 0) flag = true;
        if (flag) cout << a[pos];
        k -= pos - start,start = pos + 1,cnt++;
    }
    if (!flag) cout << 0;
    cout << endl;
    return 0;
}