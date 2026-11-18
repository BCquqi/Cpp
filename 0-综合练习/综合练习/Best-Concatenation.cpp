#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N = 2e5 + 5;
struct Node {string s; int id;} a[N];
int x[N],s[N];

signed main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i].s;
        for (char c : a[i].s) {
            if (c == 'X') x[i]++;
            else s[i] += c - '0';
        }
        a[i].id = i;
    }
    sort(a + 1,a + n + 1,[](Node p,Node q) {return x[p.id] * s[q.id] > x[q.id] * s[p.id];});
    string t = "";
    for (int i = 1;i <= n;i++) t += a[i].s;
    int sum = 0,ans = 0;
    for (int i = t.size() - 1;i >= 0;i--) {
        if (t[i] == 'X') ans += sum;
        else sum += t[i] - '0';
    }
    cout << ans << endl;
    return 0;
}