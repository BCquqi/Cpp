#include<iostream>
#include<cstdio>
#include<algorithm>
#include<list>
using namespace std;

list<int> ls;
list<int>::iterator a[100005];

void Left(int x,int y) {
	ls.insert(a[y],x);
	ls.erase(a[x]);
	a[x] = a[y], a[x]--;
	return ;
}

void Right(int x,int y) {
	auto pos = a[y]; pos++;
	ls.insert(pos,x);
	ls.erase(a[x]);
	a[x] = a[y], a[x]++;
	return ;
}

int main() {
	int n,m;
	long long cnt = 0,ans = 0;
	bool flag = false;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		ls.push_back(i);
		a[i] = ls.end();
		a[i]--;
	}
	while (m--) {
		int op;
		cin >> op;
		switch (op) {
			case 1: {
				int x,y;
				cin >> x >> y;
				if (flag) Right(x,y);
				else Left(x,y);
				continue;
			}
			case 2: {
				int x,y;
				cin >> x >> y;
				if (!flag) Right(x,y);
				else Left(x,y);
				continue;
			}
			case 3: {
				int x,y;
				cin >> x >> y;
				swap(a[x],a[y]);
				*a[x] = x, *a[y] = y;
				continue;
			}
			case 4: {
				flag = !flag;
				continue;
			}
		}
	}
	if (flag) ls.reverse();
	for (auto t : ls) {
		cnt++;
		if (cnt % 2) ans += t;
	}
	cout << ans << endl;
    return 0;
}