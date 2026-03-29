#include<iostream>
#include<cmath>
using namespace std;

const int N = 55;
struct Point {int x,y;} a[N];
int f[N],n;

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}

void Union(int x,int y) {
    int fx = find(x),fy = find(y);
    if (fx != fy) f[fx] = fy;
}

int qdis(Point x,Point y) {return abs(x.x - y.x) + abs(x.y - y.y);}

bool check(int mid) {
	for (int i = 1;i <= n;i++) f[i] = i;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			if (qdis(a[i],a[j]) <= 2 * mid) Union(i,j);
	int cnt = 0;
	for (int i = 1;i <= n;i++)
		if (f[i] == i) cnt++;
	return cnt == 1;
}

int main() {
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
	int l = 1,r = 1e9,ans;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid - 1,ans = mid;
		else l = mid + 1;
	}
	cout << ans << endl;
	return 0;
}