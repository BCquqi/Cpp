#include<iostream>
using namespace std;

const int N = 5e6 + 5;
int a[N];

int kth(int a[],int l,int r,int k) {
    int x = a[(l + r) >> 1];
    int i = l,j = r;
    while (i <= j) {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j) swap(a[i++],a[j--]);
    }
    if (k <= j - l + 1) return kth(a,l,j,k);
    else if (k >= i - l + 1) return kth(a,i,r,k - (i - l));
    else return x;
}

int main() {
	ios::sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	for (int i = 1;i <= n;i++) cin >> a[i];
	cout << kth(a,1,n,k + 1) << endl;
	return 0;
}