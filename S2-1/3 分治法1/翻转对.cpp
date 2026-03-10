#include<iostream>
using namespace std;

const int N = 2e5 + 5;
int num[N],tmp[N];

void merge(int L,int R,int mid) {
	int i = L,j = mid + 1,cur = L;
	while (i <= mid && j <= R) {
		if (num[i] < num[j]) tmp[cur++] = num[i++];
		else tmp[cur++] = num[j++];
	}
	while (i <= mid) tmp[cur++] = num[i++];
	while (j <= R) tmp[cur++] = num[j++];
	for (int i = L;i <= R;i++) num[i] = tmp[i];
}

long long merge_sort(int L,int R) {
	if (L >= R) return 0;
	int mid = (L + R) >> 1;
	long long cntL = merge_sort(L,mid),cntR = merge_sort(mid + 1,R),cnt = 0;
	for (int j = mid + 1,i = L;j <= R;j++) {
		while (2ll * num[j] >= num[i] && i <= mid) i++;
		cnt += mid - i + 1;
	}
	merge(L,R,mid);
	return cntL + cntR + cnt;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> num[i];
	cout << merge_sort(1,n) << endl;
	return 0;
}