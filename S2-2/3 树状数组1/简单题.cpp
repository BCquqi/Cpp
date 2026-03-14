#include<iostream>
using namespace std;

const int N = 1e5 + 5;
int c[N],n,m;

int lowbit(int x) {return x & -x;}
void change(int x) {while (x <= n) c[x] ^= 1,x += lowbit(x);}
long long query(int x) {
    long long ans = 0;
    while (x > 0) ans ^= c[x],x -= lowbit(x);
    return ans;
}

int main() {
	cin >> n >> m;
	for (int i = 1;i <= m;i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int l,r;
			cin >> l >> r;
			change(l); change(r + 1);
		} else {
			int i;
			cin >> i;
			cout << query(i) << endl;
		}
	}
	return 0;
}