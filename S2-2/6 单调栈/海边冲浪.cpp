#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

const int N = 5e5 + 5;
int a[N];
long long f[N];
stack<int> st;

int main() {
	int n;
	long long ans = 0;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++) {
		while (!st.empty() && a[st.top()] >= a[i]) st.pop();
		int j = st.empty() ? 0 : st.top();
		f[i] = f[j] + 1ll * (i - j) * a[i];
		st.push(i);
	}
	for (int i = 1;i <= n;i++) ans = max(ans,f[i]);
	cout << ans << endl;
	return 0;
}