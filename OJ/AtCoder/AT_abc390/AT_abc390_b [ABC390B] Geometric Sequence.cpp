#include<iostream>
using namespace std;

const int N = 105;
int a[N];

int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 2;i < n;i++)
		if (1ll * a[i] * a[i] != 1ll * a[i - 1] * a[i + 1]) {cout << "No" << endl; return 0;}
	cout << "Yes" << endl;
	return 0;
}
