#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 105;
int a[N];

int main() {
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		sum += a[i];
	}
	sum /= n;
	int ans = 0;
	for (int i = 1;i <= n;i++) {
		if (a[i] > sum) a[i + 1] += a[i] - sum,ans++;
		else if (a[i] < sum) a[i + 1] -= sum - a[i],ans++;
	}
	cout << ans << endl;
	return 0;
}