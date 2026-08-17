#include<iostream>
#include<algorithm>
#include<deque>
#include<cmath>
using namespace std;

const int N = 1e6 + 5;
int a[2 * N],s[2 * N];
char c[N];
deque<int> dq;

int main() {
    int n,p,q,x,y,ans = -1;
    cin >> n >> p >> q >> x >> y;
    for (int i = 1;i <= n;i++) {
        cin >> c[i];
        a[i] = c[i] == '+' ? 1 : -1;
        a[i + n] = a[i];
    }
    for (int i = 1;i <= 2 * n;i++) s[i] = s[i - 1] + a[i];
    int tmp = (q - p - s[n]) / 2;
    for (int i = 1;i <= 2 * n;i++) {
        while (!dq.empty() && dq.front() + n < i) dq.pop_front();
        while (!dq.empty() && s[dq.back()] >= s[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= n) {
            int pre = s[dq.front()] - s[i - n],cost = p + pre,need = 0;
            if (cost < 0) need = (-cost + 1) / 2;
            int c1 = max(need,tmp),c2 = c1 - tmp,tot = (c1 + c2) * x + (n - (i - n)) % n * y;
            if (ans == -1 || tot < ans) ans = tot;
        }
    }
    cout << ans << endl;
    return 0;
}