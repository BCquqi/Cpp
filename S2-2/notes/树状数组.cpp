int lowbit(int x) {return x & -x;}
void change(int x,int t) {while (x <= n) c[x] += t,x += lowbit(x);}
long long sum(int x) {
	long long ans = 0;
	while (x > 0) ans += c[x],x -= lowbit(x);
	return ans;
}