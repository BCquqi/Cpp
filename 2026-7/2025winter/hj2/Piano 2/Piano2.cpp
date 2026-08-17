#include<iostream>
#include<vector>
using namespace std;

const int N = 105;
int a[N],b[N];
struct Node {
	int num;
	bool flag;
}; vector<Node> c;

bool cmp(Node x,Node y) {return x.num < y.num;}

int main() {
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {cin >> a[i]; c.push_back({a[i],true});}
	for (int i = 1;i <= m;i++) {cin >> b[i]; c.push_back({b[i],false});}
	sort(c.begin(),c.end(),cmp);
	for (int i = 2;i <= n + m;i++)
		if (c[i].flag && c[i - 1].flag) {cout << "Yes" << endl; return 0;}
	cout << "No" << endl;
	return 0;
}