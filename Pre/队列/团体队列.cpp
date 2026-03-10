#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

queue<int> Q;
queue<int> q[1005];

int main(){
	int T;
	cin >> T;
	for (int i = 1;i <= T;i++)
	{
		string s;
		cin >> s;
		if (s == "ENQUEUE")
		{
			int z;
			cin >> z;
			q[z / 1000].push(z);
			if (q[z / 1000].size() == 1) Q.push(z / 1000);
		}
		else if (s == "DEQUEUE")
		{
			int t = Q.front();
			printf("%.06d\n",q[t].front());
			q[t].pop();
			if (q[t].empty()) Q.pop();
		}
		else break;
	}
	return 0;
}
