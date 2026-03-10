#include<iostream>
using namespace std;

int a[10];

int main() {
	int cnt = 0;
	for (int i = 1;i <= 5;i++) {
		cin >> a[i];
		if (a[i] <= a[i - 1]) {cnt++; swap(a[i],a[i - 1]);}
	}
	cout << (cnt == 1 ? "Yes" : "No") << endl;
	return 0;
}