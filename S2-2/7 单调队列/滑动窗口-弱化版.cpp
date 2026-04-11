#include<iostream>
#include<deque>
using namespace std;

const int N = 1e6 + 5;
int a[N];
deque<int> q;

int main() {
	int n,k;
	cin >> n >> k;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++) {
		while (!q.empty() && q.back() + k - 1 < i) q.pop_back();
		while (!q.empty() && a[q.front()] >= a[i]) q.pop_front();
		q.push_front(i);
		if (i >= k) cout << a[q.back()] << ' ';
	}
	cout << endl;
	return 0;
}