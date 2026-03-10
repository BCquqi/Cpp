#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2e5 + 5;
struct Node {
	int l,r,id;
} a[N],tmp[N];
long long ans[N];

bool cmp(Node x,Node y) {return x.l < y.l;}

void merge(int L,int R,int mid) {
	int i = L,j = mid + 1,cur = L;
	while (i <= mid && j <= R) {
		if (a[i].r < a[j].r) tmp[cur++] = a[i++];
		else tmp[cur++] = a[j++];
	}
	while (i <= mid) tmp[cur++] = a[i++];
	while (j <= R) tmp[cur++] = a[j++];
	for (int i = L;i <= R;i++) a[i] = tmp[i];
}

void merge_sort(int L,int R) {
	if (L >= R) return ;
	int mid = (L + R) >> 1;
	merge_sort(L,mid); merge_sort(mid + 1,R); 
	for (int j = mid + 1,i = L;i <= mid;i++) {
		while (a[i].r >= a[j].r && j <= R) j++;
		ans[a[i].id] += j - mid - 1;
	}
	merge(L,R,mid);
}

int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> a[i].l >> a[i].r;
		a[i].id = i;
	}
	sort(a + 1,a + n + 1,cmp);
	merge_sort(1,n);
	for (int i = 1;i <= n;i++) cout << ans[i] << endl;
	return 0;
}