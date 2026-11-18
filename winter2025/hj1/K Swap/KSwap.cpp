#include<iostream>
#include<vector>
using namespace std;

const int N = 2e5 + 5;
int a[N],b[N],curv = -1,curb = 0;
vector<int> v[N];

int main() {
	int n,k;
	cin >> n >> k;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		v[i % k].push_back(a[i]);
	}
	for (int i = 0;i < k;i++) sort(v[i].begin(),v[i].end());
	for (int i = 1;i <= n;i++) {
		if (i % k == 1) curv++;
		b[++curb] = v[i % k][curv];
	}
	bool flag = true;
	for (int i = 2;i <= n;i++) flag &= (b[i] >= b[i - 1]);
	cout << (flag ? "Yes" : "No") << endl;
	return 0;
}