#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

priority_queue<int> pq;
long long sum = 0;

void solve()
{
	string op;
	cin >> op;
	if (op == "score")
	{
		int x;
		cin >> x;
		pq.push(x);
		sum += x;
	}
	if (op == "delete")
	{
		sum -= pq.top();
		pq.pop();
	}
	if (op == "display")
		printf("%.3lf\n",1.0 * sum / pq.size());
}

int main(){
	int m;
	cin >> m;
	while (m--) solve();
	return 0;
}