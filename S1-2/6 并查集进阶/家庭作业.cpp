#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e6 + 5;
struct Node {int t,s;} a[N];
bool flag[N];
int f[N];

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}

void Union(int x,int y) {
    int fx = find(x),fy = find(y);
    if (fx != fy) f[fx] = fy;
}

int main() {
	int n;
	long long ans = 0;
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i].t >> a[i].s;
	for (int i = 1;i <= n;i++) f[i] = i;
	sort(a + 1,a + n + 1,[](Node x,Node y) {return x.s > y.s;});
	for (int i = 1;i <= n;i++) {
		int s = a[i].s,t = a[i].t;
		for (int j = find(t);j >= 1;j = find(j)) {
			ans += s;
			f[j] = find(j - 1);
			break;
		}
	}
	cout << ans << endl;
	return 0;
}