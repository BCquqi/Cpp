#include<iostream>
#include<algorithm>
using namespace std;

// dpa[]以游泳结尾第i天最大幸福值
// dpb[]以捉虫结尾第i天最大幸福值
// dpc[]以写作业结尾第i天最大幸福值

const int N = 100005;
int dpa[N],dpb[N],dpc[N],a[N],b[N],c[N];

int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i] >> b[i] >> c[i];
	dpa[1] = a[1],dpb[1] = b[1],dpc[1] = c[1];
	for (int i = 1;i <= n;i++)
	{
		dpa[i] = a[i] + max(dpb[i - 1],dpc[i - 1]);
		dpb[i] = b[i] + max(dpa[i - 1],dpc[i - 1]);
		dpc[i] = c[i] + max(dpa[i - 1],dpb[i - 1]);
	}
	cout << max(dpa[n],max(dpb[n],dpc[n])) << endl;
	return 0;
}
