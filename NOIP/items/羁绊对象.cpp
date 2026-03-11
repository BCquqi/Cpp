#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime> 
using namespace std;

int inter(int num){
	int c=1;
	srand(time(0));
	for (int i=2;i<=num-1;i++){
		if (i>=38)break;
		if (num%i==0){
			return i;
			c=0;
		}
	}
	if (c)return(rand()%1+(num-1));
}

int intre(int num,int a){
	if (num%a==0){
		int k=num/a;
		if (k>37){
			while (k>37){
				k/=2;
			}
		}
		return k;
	}
	else return num-a;
}

int main()
{
	int n,a,b;
	printf("输入整数(至多1369),输出班级羁绊对象:");
	scanf("%d",&n);
	if (n>1369)printf("输入不正确");
	else{
		a=inter(n);
		b=intre(n,a);
		if (a==b)printf("%d是自恋狂",a);
		else printf("%d和%d是羁绊对象",a,b);	
	}
	
	return 0;
}
