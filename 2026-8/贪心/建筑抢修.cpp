#include<iostream>
#include<queue>
#include<algorithm>
#define int long long
using namespace std;

const int N = 1.5e5 + 5;
struct Node {int t1,t2;} s[N];
priority_queue<int> q;

signed main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> s[i].t1 >> s[i].t2;
	sort(s + 1,s + n + 1,[](Node x,Node y) {return x.t2 < y.t2;});
	int t = 0,ans = 0;
	for (int i = 1;i <= n;i++) {
		t += s[i].t1;
		q.push(s[i].t1);
		if (t <= s[i].t2) ans++; 
		else {
			t -= q.top();
			q.pop(); 
		}
	}
	cout << ans << endl;
	return 0;
} 
