#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;

map<int,int> v,cnt;

int main() {
	int n;
	cin >> n;
	while (n--)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int x,y;
			cin >> x >> y;
			cnt[v[x]]--;
			if (cnt[v[x]] <= 0) cnt.erase(v[x]);
			v[x] = y;
			cnt[y]++;
		}
		else if (op == 2)
		{
			cout << cnt.begin() -> first << endl;
		}
		else 
		{
			cout << cnt.rbegin() -> first << endl;
		}
	}
    return 0;
}
