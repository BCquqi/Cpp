#include<iostream>
using namespace std;

const int N = 1005,P = 1009,Q = 1051;
unsigned long long h[N][N],h1[N][N],h2[N][N],p[N],q[N],a[N][N];
int n,m;
long long ans = -1;

unsigned long long Hash(unsigned long long h[N][N],int x1,int y1,int x2,int y2) {
    return h[x2][y2] - h[x1 - 1][y2] * p[x2 - x1 + 1] - h[x2][y1 - 1] * q[y2 - y1 + 1] + h[x1 - 1][y1 - 1] * p[x2 - x1 + 1] * q[y2 - y1 + 1];
}

bool check(int x1,int y1,int x2,int y2) {
    return Hash(h,x1,y1,x2,y2) == Hash(h1,n - x2 + 1,m - y2 + 1,n - x1 + 1,m - y1 + 1);
}

int main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++) {
        	char tmp;
        	cin >> tmp;
            a[i][j] = tmp - '0';
        }
    p[0] = q[0] = 1;
    for (int i = 1;i <= N;i++) p[i] = p[i - 1] * P,q[i] = q[i - 1] * Q;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            h[i][j] = h[i - 1][j] * P + h[i][j - 1] * Q - h[i - 1][j - 1] * P * Q + a[i][j],
            h1[i][j] = h1[i - 1][j] * P + h1[i][j - 1] * Q - h1[i - 1][j - 1] * P * Q + a[n - i + 1][m - j + 1];
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++) {
            int L = 1,R = min(min(i - 1,j - 1),min(n - i,m - j)),len = -1e9;
            while (L <= R) {
                int mid = L + R >> 1;
                if (check(i - mid,j - mid,i + mid,j + mid)) len = mid,L = mid + 1;
                else R = mid - 1;
            }
            ans = max(ans,2ll * len + 1);
            L = 1,R = min(min(n - i,m - j),min(i,j)),len = -1e9;
            while (L <= R) {
                int mid = L + R >> 1;
                if (check(i - mid + 1,j - mid + 1,i + mid,j + mid)) len = mid,L = mid + 1;
                else R = mid - 1;
            }
            ans = max(ans,2ll * len);
        }
    cout << ans << endl;
    return 0;
}