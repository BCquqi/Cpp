#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

const int N = 1005;
const double eps = 1e-5;
int a[N],b[N],n,k;
double c[N];

bool check(double mid) {
	for (int i = 1;i <= n;i++) c[i] = a[i] - mid * b[i];
	sort(c + 1,c + n + 1,greater<double>());
	double sum = 0;
	for (int i = 1;i <= n - k;i++) sum += c[i];
	return (sum >= 0);
}

int main() {
	cin >> n >> k;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++) cin >> b[i];
	double L = 0,R = 1,ans = 0;
	while (R - L >= eps) {
	    double mid = (L + R) / 2;
	    if (check(mid)) {
	        ans = mid;
	        L = mid;
	    } else R = mid;
	}
	cout << round(ans * 100) << endl;
	return 0;
}