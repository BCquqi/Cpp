#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
struct Node {int a,b;} s[N];
priority_queue<int> q;

int main() {
	int n,m;
	long long ans = 0;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> s[i].a >> s[i].b;
	sort(s + 1,s + n + 1,[](Node x,Node y) {return x.a < y.a;});
	int cur = 1;
	for (int i = 1;i <= m;i++) { // i 枚举剩余天数，必须天数倒着算来贪心 
		while (s[cur].a <= i && cur <= n) {
			q.push(s[cur].b); // 可以采用 
			cur++; // 在这里加，不然会出错 
		}
		if (!q.empty()) {
			ans += q.top();
			q.pop(); 
		}
	}
	cout << ans << endl;
	return 0;
}
