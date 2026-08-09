#include<iostream>
using namespace std;

int k;
string n;
bool flag = false;

void add(int x) {
    if (n[x] < '9') n[x]++;
    else if (x == 0) n[x] = '0',n = '1' + n,flag = true,k++; // 加到第一位
    else {
        n[x] = '0';
        add(x - 1);
    }
}

void solve() {
    cin >> k >> n;
    cout << n;
    for (int i = k - 1,cur = k - 1;i >= 1;i--,cur--) {
        if (n[cur] <= '4')
            for (int j = cur;j < k;j++) n[j] = '0';
        else {
            add(cur - 1);
            for (int j = cur;j < k;j++) n[j] = '0';
            if (flag) cur++,flag = false;
        }
        cout << " -> " << n;
    }
    cout << endl;
    return ;
}

int main() {
    freopen("throw.in","r",stdin);
    freopen("throw.out","w",stdout);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}