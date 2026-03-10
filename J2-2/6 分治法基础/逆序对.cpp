#include<iostream>
using namespace std;

const int N = 5e5 + 5;
int a[N],tmp[N];

long long merge(int a[],int l,int r) {
	if (l >= r) return 0;
    int mid = l + r >> 1;
    long long lcnt = merge(a,l,mid),rcnt = merge(a,mid + 1,r),cnt = 0,i = l,j = mid + 1,cur = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) tmp[cur++] = a[i++];
        else tmp[cur++] = a[j++],cnt += mid - i + 1;
    }
    while (i <= mid) tmp[cur++] = a[i++];
    while (j <= r) tmp[cur++] = a[j++];
    for (int i = l;i <= r;i++) a[i] = tmp[i];
    return cnt + lcnt + rcnt;
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	cout << merge(a,1,n) << endl;
	return 0;
}