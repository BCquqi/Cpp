#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5,mod = 1e8 - 3;
struct Node {
	int num,id;
} a[N],b[N];
int c[N],tmp[N];

bool cmp(Node x,Node y) {
	return x.num < y.num;
}

int merge(int a[],int l,int r) {
	if (l >= r) return 0;
	int mid = l + r >> 1;
	long long lcnt = merge(a,l,mid) % mod,rcnt = merge(a,mid + 1,r) % mod,cnt = 0,i = l,j = mid + 1,cur = l;
	while (i <= mid && j <= r) {
		if (a[i] <= a[j]) tmp[cur++] = a[i++];
		else tmp[cur++] = a[j++],cnt = (cnt + mid - i + 1) % mod;
	}
	while (i <= mid) tmp[cur++] = a[i++];
    while (j <= r) tmp[cur++] = a[j++];
    for (int i = l;i <= r;i++) a[i] = tmp[i];
	return (cnt + lcnt + rcnt) % mod;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {cin >> a[i].num;a[i].id = i;}
	for (int i = 1;i <= n;i++) {cin >> b[i].num;b[i].id = i;}
	sort(a + 1,a + n + 1,cmp); sort(b + 1,b + n + 1,cmp);
	for (int i = 1;i <= n;i++) c[a[i].id] = b[i].id;
	cout << merge(c,1,n) << endl;
	return 0;
}