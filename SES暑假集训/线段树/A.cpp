#include<iostream>
using namespace std;

const int N = 1e5 + 5;
int a[N],st[N][25],lg[N];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int main() {
    int n,m;
    n = read(); m = read();
    for (int i = 1;i <= n;i++) a[i] = read();
    lg[0] = -1;
    for (int k = 1;k <= N;k++) lg[k] = lg[k >> 1] + 1;
    for (int i = 1;i <= n;i++) st[i][0] = a[i];
    for (int j = 1;j <= 20;j++)
        for (int i = 1;i + (1 << j) - 1 <= n;i++)
            st[i][j] = max(st[i][j - 1],st[i + (1 << (j - 1))][j - 1]);
    while (m--) {
        int l,r;
        l = read(); r = read();
        int k = lg[r - l + 1];
        cout << max(st[l][k],st[r - (1 << k) + 1][k]) << endl;
    }
    return 0;
}