#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

const int N = 5e4 + 5;
int x[N],h[N];
bool l[N],r[N];
deque<int> q;
struct Node {
	int x,h;
} s[N];

int main() {
	int n,d,ans = 0;
	cin >> n >> d;
	for (int i = 1;i <= n;i++) cin >> s[i].x >> s[i].h;
	sort(s + 1,s + n + 1,[](Node x,Node y) {return x.x < y.x;});
	for (int i = 1;i <= n;i++) {
		while (!q.empty() && s[q.back()].x + d < s[i].x) q.pop_back();
		while (!q.empty() && s[q.front()].h <= s[i].h) q.pop_front();
		q.push_front(i);
		if (s[q.back()].h >= 2 * s[i].h) l[i] = true;
	}
	q.clear();
	for (int i = n;i >= 1;i--) {
		while (!q.empty() && s[q.front()].x - d > s[i].x) q.pop_front();
		while (!q.empty() && s[q.back()].h <= s[i].h) q.pop_back();
		q.push_back(i);
		if (s[q.front()].h >= 2 * s[i].h) r[i] = true;
	}
	for (int i = 1;i <= n;i++) ans += (l[i] && r[i]);
	cout << ans << endl;
	return 0;
}