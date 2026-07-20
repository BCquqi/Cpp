#include<iostream>
using namespace std;

set<int> s;

int main() {
	int n;
	cin >> n;
	while (n--) {
		int a,b;
		cin >> a >> b;
		if (a == 0) {
			
		} else {
			if (s.empty()) s.insert(b);
			else {
				/* 找宠物集合找接近数 */
				auto it1 = lower_bound(x);
				auto it2 = it1;
				if (it2 != s.begin()) it2--;
				if (abs(b - *it1)) ans += 
				else /* ... */
			}
		}
	}
	return 0;
}