#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

priority_queue<int,vector<int>,greater<int> > pq;

int main()
{
	int n,ans = 0;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		int a;
		cin >> a;
		pq.push(a);
	}
	for (int i = 1;i < n;i++) {
		int tmp = 0;
		tmp += pq.top(); pq.pop();
		tmp += pq.top(); pq.pop();
		pq.push(tmp);
		ans += tmp;
	}
	cout << ans << endl;
	return 0;
}