#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e7 + 5;
int f[N];
long long ans = 0;
bool prime[N];

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}

void merge(int x,int y) {
    int fx = find(x),fy = find(y);
    if (fx != fy) f[fx] = fy, ans += x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int n;
    cin >> n;
    memset(prime,true,sizeof prime);
    prime[1] = false;
    for (int i = 2;i <= n;i++) {
        if (!prime[i]) continue;
        for (int j = 2;i * j <= n;j++)
            prime[i * j] = false;
    }
    for (int i = 1;i <= n;i++) f[i] = i;
    for (int i = n / 2;i >= 1;i--)
        for (int p = 2;p * i <= n;p++) {
            if (!prime[p]) continue;
            merge(i,p * i);
        }
    cout << ans << '\n';
    return 0;
}