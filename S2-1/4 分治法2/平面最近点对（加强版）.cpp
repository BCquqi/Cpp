#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 1e6 + 5;
struct Node {
	int x,y;
} a[N],tmp[N],b[N];

bool cmp(Node x,Node y) {return x.x < y.x;}

long long cald(int x1,int y1,int x2,int y2) {
	return 1ll * (x2 - x1) * (x2 - x1) + 1ll * (y2 - y1) * (y2 - y1);
}

void merge(int L,int R,int mid) {
	int i = L,j = mid + 1,cur = L;
	while (i <= mid && j <= R) {
		if (a[i].y < a[j].y) tmp[cur++] = a[i++];
		else tmp[cur++] = a[j++];
	}
	while (i <= mid) tmp[cur++] = a[i++];
	while (j <= R) tmp[cur++] = a[j++];
	for (int i = L;i <= R;i++) a[i] = tmp[i];
}

long long merge_sort(int L,int R) {
	if (L >= R) return 1e18;
	int mid = (L + R) >> 1,cur = 0;
	int midx = a[mid].x;
	long long disL = merge_sort(L,mid),disR = merge_sort(mid + 1,R),dis = min(disL,disR);
	for (int i = L;i <= R;i++)
		if (1ll * (a[i].x - midx) * (a[i].x - midx) <= dis) b[++cur] = a[i];
	merge(L,R,mid);
	for (int i = 1;i <= cur;i++)
		for (int j = i + 1;j <= cur;j++) {
			long long dy = a[i].y - a[j].y;
			if (dy * dy > dis) break;
			dis = min(dis,cald(b[i].x,b[i].y,b[j].x,b[j].y));
		}
	return dis;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
	sort(a + 1,a + n + 1,cmp);
	cout << merge_sort(1,n) << endl;
	return 0;
}