#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

const int N = 1e6 + 5;
struct Node {int x,y;} a[N];
deque<int> q;
int minn[N],maxn[N],n,d;

bool check(int w) {
	q.clear();
	for (int i = 1;i <= n;i++) {
		while (!q.empty() && a[q.back()].x + w < a[i].x) q.pop_back();
		while (!q.empty() && a[q.front()].y >= a[i].y) q.pop_front();
		q.push_front(i);
		minn[i] = a[q.back()].y;
	}
	q.clear();
	for (int i = 1;i <= n;i++) {
		while (!q.empty() && a[q.back()].x + w < a[i].x) q.pop_back();
		while (!q.empty() && a[q.front()].y <= a[i].y) q.pop_front();
		q.push_front(i);
		maxn[i] = a[q.back()].y;
	}
	for (int i = 1;i <= n;i++)
		if (maxn[i] - minn[i] >= d) return true;
	return false;
}

int main() {
	cin >> n >> d;
	for (int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
	sort(a + 1,a + n + 1,[](Node x,Node y) {return x.x < y.x;});
	int L = 1,R = 1e6,ans = 0;
	while (L <= R) {
		int mid = L + R >> 1;
		if (check(mid)) R = mid - 1,ans = mid;
		else L = mid + 1;
	}
	cout << (ans == 0 ? -1 : ans) << endl;
	return 0;
}