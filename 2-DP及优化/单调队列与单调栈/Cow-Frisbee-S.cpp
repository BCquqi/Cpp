#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

const int N = 3e5 + 5;
int l[N],r[N];
long long h[N],ans = 0;
stack<int> stl,str;

int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> h[i];
	for (int i = 1;i <= n;i++) {
		while (!stl.empty() && h[stl.top()] <= h[i]) stl.pop();
		l[i] = stl.empty() ? 0 : stl.top();
		if (l[i]) ans += i - l[i] + 1;
		stl.push(i);
	}
	for (int i = n;i >= 1;i--) {
		while (!str.empty() && h[str.top()] <= h[i]) str.pop();
		r[i] = str.empty() ? 0 : str.top();
		if (r[i]) ans += r[i] - i + 1;
		str.push(i);
	}
	cout << ans << endl;
	return 0;
}