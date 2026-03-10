#include<cstdio>
using namespace std;

const int N = 5e5 + 5;
int a[N],tmp[N];

void merge(int L,int R,int mid) {
	int i = L,j = mid + 1,cur = L;
	while (i <= mid && j <= R) {
		if (a[i] < a[j]) tmp[cur++] = a[i++];
		else tmp[cur++] = a[j++];
	}
	while (i <= mid) tmp[cur++] = a[i++];
	while (j <= R) tmp[cur++] = a[j++];
	for (int i = L;i <= R;i++) a[i] = tmp[i];
}

long long merge_sort(int L,int R) {
	if (L >= R) return 0;
	int mid = (L + R) >> 1;
	long long cntL = merge_sort(L,mid),cntR = merge_sort(mid + 1,R);
	long long cnt = 0;
	for (int j = mid + 1,i = L;j <= R;j++) {
		while (a[j] >= a[i] && i <= mid) i++;
		cnt += mid - i + 1;
	}
	merge(L,R,mid);
	return cntL + cntR + cnt;
}

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	printf("%lld\n",merge_sort(1,n));
	return 0;
}