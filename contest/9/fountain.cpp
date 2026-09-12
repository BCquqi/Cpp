#include<iostream>
#include<algorithm>
using namespace std;

const int N = 3005;
int n,cnt0[N],cnt1[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("fountain.in","r",stdin);
    freopen("fountain.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++) {
            char c;
            cin >> c;
            if (c == '0') cnt0[i]++;
            else cnt1[j]++;
        }
    // 思路：构造一个全 1 列，其他的都用这个列弥补
    int cnt = 0,change = 1e9;
    for (int i = 1;i <= n;i++) {
        if (cnt1[i] != n) cnt++;
        change = min(change,cnt0[i] + (cnt1[i] == 0)); // 若该行全为0，则需要额外加1
    }
    cout << cnt + change << endl;
    return 0;
}