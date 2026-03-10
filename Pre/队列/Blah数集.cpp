#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

queue<long long> q1,q2;

int main(){
	int a,n;
	cin >> a >> n;
	q1.push(2 * a + 1);
	q2.push(3 * a + 1);
	for (int i = 2;i <= n;i++)
	{
		a = min(q1.front(),q2.front());
		q1.push(2 * a + 1);
		q2.push(3 * a + 1);
		if (a == q1.front()) q1.pop();
		if (a == q2.front()) q2.pop();
	}
	cout << a << endl;
	return 0;
}
