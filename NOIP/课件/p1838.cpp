#include<bits/stdc++.h>
using namespace std;
int c[10]={448,56,7,292,146,73,273,84};//所有的状态
char a[10];
int main(){
	int x=0,y=0,len;
	cin>>a;//scanf("%s",a);
	//cout<<a;
	len=strlen(a);
	//cout<<len;
	for(int i=0;i<len;i++){
		if(i%2==0)
		  x=x+(1<<(9-(a[i]-'0')));//第1个人的棋局字符所对应的整数
		else
		  y=y+(1<<(9-(a[i]-'0')));//第2个人的棋局字符所对应的整数   
	}
	for(int i=0;i<=7;i++){//枚举所有赢的棋局状态 
	  if((x&c[i])==c[i])
	   {
	   	cout<<"xiaoa wins."<<endl;
	   	return 0;
	   }
	  if((y&c[i])==c[i])  
	    {
	   	cout<<"uim wins."<<endl;
	   	return 0;
	   }
	}
	cout<<"drew"<<endl;
	
	return 0;
} 
