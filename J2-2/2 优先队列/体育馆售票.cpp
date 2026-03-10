#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

const int N = 1e6 + 5;
priority_queue<int,vector<int>,less<int> > pq;

int main(){
	int m,n;
	long long ans = 0;
	cin >> m >> n;
	for (int i = 1;i <= m;i++)
	{
		int x; cin >> x;
		pq.push(x);
	}
	while (n--)
	{
		int tmp = pq.top();
		pq.pop(); 
		ans += tmp;
		pq.push(tmp - 1);
	}
	cout << ans << endl;
	return 0;
}