// 本题为填空题
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
int f[50];
//f[n]表示上n级台阶的方法数
int main(){
	int n;
	cin>>n;
	f[1]= 1          ;
	f[2]= 2          ;
	for(int i=3;i<=n;i++){
		f[i] = f[i - 1] + f[i - 2]          ;
	}
	cout<<f[n]<<endl;
	return 0;
}

#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
int f[50];
//f[n]表示只由1,3,4组成的数码和为n的数的个数
int main(){
	int n;
	cin>>n;
	f[1]= 1          ;
	f[2]= 1          ;
	f[3]= 2          ;
	f[4]= 4          ;
	for(int i=5;i<=n;i++){
		f[i] = f[i - 1] + f[i - 3] + f[i - 4]         ;
	}
	cout<<f[n]<<endl;
	return 0;
}

#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
int a[50],b[50],c[50];
//a[n]表示以1结尾的数的n位数的个数
//b[n]表示以2结尾的数的n位数的个数
//c[n]表示以3结尾的数的n位数的个数
int main(){
	int n;
	cin>>n;
	a[1]= 1   ;
	b[1]= 1   ;
	c[1]= 1   ;
	for(int i=2;i<=n;i++){
		a[i]= b[i - 1] + c[i - 1]          ;
		b[i]= a[i - 1] + b[i - 1] + c[i - 1]          ;
		c[i]= a[i - 1] + b[i - 1] + c[i - 1]          ;
	}
	cout<< a[n] + b[n] + c[n]          <<endl;
	return 0;
}

#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
LL a[50],b[50];
//a[n]表示以5结尾的n位数个数
//b[n]表示不以5结尾的n位数个数
int main(){
	int n;
	cin>>n;
	a[1]= 1   ;
	b[1]= 8   ;
	for(int i=2;i<=n;i++){
		a[i]= a[i - 1] + b[i - 1]          ;
		b[i]= 8 * a[i - 1] + b[i - 1] * 9          ;
	}
	cout<< a[n] + b[n] <<endl;
	return 0;
}

#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
int a[50],b[50],c[50],d[50];
//a[n]表示长为n的以AA结尾的字符串个数
//b[n]表示长为n的以AB结尾的字符串个数
//c[n]表示长为n的以BA结尾的字符串个数
//d[n]表示长为n的以BB结尾的字符串个数
int main(){
	int n;
	cin>>n;
	a[2]= 1   ;
	b[2]= 1   ;
	c[2]= 1   ;
	d[2]= 1   ;
	for(int i=3;i<=n;i++){
		a[i]= a[i - 1] + c[i - 1]          ;
		b[i]= c[i - 1]          ;
		c[i]= b[i - 1] + d[i - 1]         ;
		d[i]= b[i - 1] + d[i - 1]         ;
	}
	cout<< a[n] + b[n] + c[n] + d[n]          <<endl;
	return 0;
}

#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
LL x[50],y[50];
//x[n]表示包含偶数个1的n位数的个数
//y[n]表示包含奇数个1的n位数的个数
int main(){
	int n;
	cin>>n;
	x[1]= 8   ;
	y[1]= 1   ;
	for(int i=2;i<=n;i++){
		x[i]= x[i - 1] * 9 + y[i - 1] * 1         ;
		y[i]= y[i - 1] * 9 + x[i - 1] * 1          ;
	}
	cout<<x[n]<<endl;
	return 0;
}
