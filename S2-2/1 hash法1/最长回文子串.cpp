#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int P = 131,N = 1e6 + 5;
unsigned long long p[N],hs[N],ht[N];
int n;

bool check1(int mid) {
    for (int i = mid + 1;i <= n - mid;i++) {
        int L = i - mid,R = i + mid;
        int tL = n - R + 1,tR = n - L + 1;
        if (hs[R] - hs[L - 1] *  p[R - L + 1] == ht[tR] - ht[tL - 1] * p[tR - tL + 1]) return true;
    }
    return false;
}

bool check0(int mid) {
    for (int i = mid;i <= n - mid;i++) {
        int L = i - mid + 1,R = i + mid;
        int tL = n - R + 1,tR = n - L + 1;
        if (hs[R] - hs[L - 1] *  p[R - L + 1] == ht[tR] - ht[tL - 1] * p[tR - tL + 1]) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    string t = s;
    n = s.size();
    reverse(t.begin(),t.end());
    s = ' ' + s,t = ' ' + t;
    p[0] = 1;
    for (int i = 1;i <= n;i++) {
        p[i] = p[i - 1] * P;
        hs[i] = hs[i - 1] * P + s[i];
        ht[i] = ht[i - 1] * P + t[i];
    }
    int L = 0,R = (n - 1) / 2,ans = 0;
    while (L <= R) {
        int mid = L + R >> 1;
        if (check1(mid)) {
            L = mid + 1;
            ans = max(ans,2 * mid + 1);
        }
        else R = mid - 1;
    }
    L = 1,R = n / 2;
    while (L <= R) {
        int mid = L + R >> 1;
        if (check0(mid)) {
            L = mid + 1;
            ans = max(ans,2 * mid);
        }
        else R = mid - 1;
    }
    cout << ans << endl;
    return 0;
}