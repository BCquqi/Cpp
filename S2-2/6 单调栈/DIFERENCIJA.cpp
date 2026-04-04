#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

const int N = 3e5 + 5;
int a[N],lb[N],ls[N],rb[N],rs[N];
stack<long long> stlb,stls,strb,strs;

int main() {
	int n;
	long long ansmax = 0,ansmin = 0;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++) {
		while (!stlb.empty() && a[stlb.top()] <= a[i]) stlb.pop();
		lb[i] = stlb.empty() ? 0 : stlb.top();
		stlb.push(i);
	}
	for (int i = n;i >= 1;i--) {
		while (!strb.empty() && a[strb.top()] < a[i]) strb.pop();
		rb[i] = strb.empty() ? n + 1 : strb.top();
		strb.push(i);
	}
	for (int i = 1;i <= n;i++) {
		while (!stls.empty() && a[stls.top()] >= a[i]) stls.pop();
		ls[i] = stls.empty() ? 0 : stls.top();
		stls.push(i);
	}
	for (int i = n;i >= 1;i--) {
		while (!strs.empty() && a[strs.top()] > a[i]) strs.pop();
		rs[i] = strs.empty() ? n + 1 : strs.top();
		strs.push(i);
	}
	for (int i = 1;i <= n;i++)
		ansmax += 1ll * (i - lb[i]) * (rb[i] - i) * a[i], ansmin += 1ll * (i - ls[i]) * (rs[i] - i) * a[i];
	cout << ansmax - ansmin << endl;
	return 0;
}