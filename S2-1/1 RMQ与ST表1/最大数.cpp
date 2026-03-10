#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2e5 + 5;
int a[N],lg[N],st[N][30],m,d,len,t = 0;

int query(int l,int r) {
	int k = lg[r - l + 1];
	return max(st[l][k],st[r - (1 << k) + 1][k]);
}

void insert() {
	int n;
	cin >> n;
	n = (n + t) % d,a[++len] = n,st[len][0] = a[len];
	for (int j = 1;j <= lg[len];j++)
		st[len - (1 << j) + 1][j] = max(query(len - (1 << j) + 1,len - 1),a[len]);
}

int main() {
	cin >> m >> d;
	lg[1] = 0;
	for (int i = 2;i <= m;i++) lg[i] = lg[i / 2] + 1;
	while (m--) {
		char op;
		cin >> op;
		if (op == 'Q') {
            int l;
            cin >> l;
            t = query(len - l + 1,len);
            cout << t << endl;
        }
		else insert();
	}
	return 0;
}