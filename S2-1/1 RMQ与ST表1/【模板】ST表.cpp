#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
int a[N],lg[N],st[N][30];

inline int read()
{
	int x = 0,f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') {x = x * 10 + ch - 48; ch = getchar(); }
	return x * f;
}

int main() {
	int n,m;
	n = read(), m = read();
	lg[1] = 0;
	for (int i = 2;i <= n;i++) lg[i] = lg[i / 2] + 1;
	for (int i = 1;i <= n;i++) a[i] = read();
	for (int i = 1;i <= n;i++) st[i][0] = a[i];
	for (int j = 1;j <= lg[n];j++)
		for (int i = 1;i + (1 << j) - 1 <= n;i++)
			st[i][j] = max(st[i][j - 1],st[i + (1 << j - 1)][j - 1]);
	while (m--) {
		int l,r;
		l = read(),r = read();
		int k = lg[r - l + 1];
		printf("%d\n",max(st[l][k],st[r - (1 << k) + 1][k]));
	}
	return 0;
}