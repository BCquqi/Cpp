#include<iostream>
#include<algorithm>
using namespace std;

const int P = 131,mod = 1e9 + 7,N = 5e5 + 5;
unsigned long long hs[N],ht[N],p[N];
int n;

bool check(int i,int mid) {
    int L = i - mid + 1,R = i + mid;
    int tL = n - R + 1,tR = n - L + 1;
    return hs[R] - hs[L - 1] * p[R - L + 1] == ht[tR] - ht[tL - 1] * p[tR - tL + 1];
}

int main() {
    string s,t = "";
    cin >> n >> s;
    for (int i = 0;i < s.size();i++) t += (s[i] == '0') ? '1' : '0';
    reverse(t.begin(),t.end());
    s = ' ' + s,t = ' ' + t;
    p[0] = 1;
    for (int i = 1;i <= n;i++) {
        p[i] = p[i - 1] * P;
        hs[i] = hs[i - 1] * P + s[i];
        ht[i] = ht[i - 1] * P + t[i];
    }
    int ans = 0;
    for (int i = 1;i < n;i++) {
        int L = 1,R = min(i,n - i),maxlen = 0;
        while (L <= R) {
            int mid = L + R >> 1;
            if (check(i,mid)) maxlen = mid,L = mid + 1;
            else R = mid - 1;
        }
        ans += maxlen;
    }
    cout << ans << endl;
    return 0;
}