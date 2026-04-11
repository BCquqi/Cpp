#include<iostream>
#include<deque>
using namespace std;

const int N = 5e4 + 5;
int x[N],h[N];
deque<int> q;
struct Node {
	int x,h;
} s[N];

int main() {
	int n,d;
	cin >> n >> d;
	for (int i = 1;i <= n;i++) cin >> s[i].x >> s[i].h;
	sort(s + 1,s + n + 1,[](Node x,Node y) {return x.x < y.x;});
	for (int i = 1;i <= n;i++) {
		while (!q.empty() && q.back() + d - 1 < i) q.pop_back();
		while (!q.empty() && s[q.front()].h >= s[i].h) q.pop_front();
		q.push_front(i);
		while (!q.empty() && q.front() - d + 1 > i) q.pop_front();
		while (!q.empty() && s[q.back()].h >= s[i].h) q.pop_back();
		q.push_back(i);
		
	}
	return 0;
}