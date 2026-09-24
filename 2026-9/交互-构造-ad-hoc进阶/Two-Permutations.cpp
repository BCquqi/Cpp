#include<iostream>
#include<vector>
#define int long long
using namespace std;

const int N = 2505;

int n,m,a[N],b[N];
vector<int> ans1,ans2;

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= m;i++) cin >> b[i];
    for (int i = 1;i <= n;i++) {
        if (a[i] == i) continue;
        for (int j = i;j <= n;j++)
            if (a[j] == i) {
                ans1.push_back(i), ans1.push_back(j - i), ans1.push_back(n - j + 1);
                swap(a[i],a[j]);
                break;
            }
    }
    for (int i = 1;i <= m;i++) {
        if (b[i] == i) continue;
        for (int j = i;j <= m;j++)
            if (b[j] == i) {
                ans2.push_back(i), ans2.push_back(j - i), ans2.push_back(m - j + 1);
                swap(b[i],b[j]);
                break;
            }
    }
    if (ans1.size() % 2 != ans2.size() % 2) {
        if (n % 2 == 1) for (int i = 1;i <= n;i++) ans1.push_back(n);
        else if (m % 2 == 1) for (int i = 1;i <= m;i++) ans2.push_back(m);
        else {
            cout << -1 << endl;
            return 0;
        }
    }
    while (ans1.size() < ans2.size())
        ans1.push_back(1), ans1.push_back(n);
    while (ans2.size() < ans1.size())
        ans2.push_back(1), ans2.push_back(m);
    cout << ans1.size() << endl;
    for (int i = 0;i < ans1.size();i++)
        cout << ans1[i] << ' ' << ans2[i] << endl;
    return 0;
}