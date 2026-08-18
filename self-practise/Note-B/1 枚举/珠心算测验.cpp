#include<iostream>
using namespace std;

int a[105],box[10005];

int main() {
    int n,ans = 0;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        box[a[i]] = true;
    }
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++) {
            if (j == i) continue;
            if (a[i] - a[j] <= 0 || a[i] - a[j] == a[j]) continue;
            if (box[a[i] - a[j]]) {ans++; break;}
        }
    cout << ans << endl;
    return 0;
}