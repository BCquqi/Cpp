#include<iostream>
using namespace std;

const int N = 2e4 + 5;
pair<int,int> a[N];

int main() {
	int n,ans = 0;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		int t,l,r;
		cin >> t >> l >> r;
		l *= 2,r *= 2;
		switch(t) {
			case 1: {a[i] = {l,r}; continue; }
			case 2: {a[i] = {l,r - 1}; continue; }
			case 3: {a[i] = {l + 1,r}; continue; }
			case 4: {a[i] = {l + 1,r - 1}; continue; }
		}
	}
	for (int i = 1;i <= n;i++)
		for (int j = i + 1;j <= n;j++)
			if (a[i].first <= a[j].second && a[j].first <= a[i].second) ans++;
	cout << ans << endl;
	return 0;
}