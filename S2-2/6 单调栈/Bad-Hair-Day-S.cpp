#include<iostream>
#include<stack>
using namespace std;

const int N = 8e4 + 5;
int a[N];
stack<int> st;

int main() {
	int n,ans = 0;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++) {
		while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        ans += st.size();
		st.push(i);
	}
    cout << ans << endl;
	return 0;
}