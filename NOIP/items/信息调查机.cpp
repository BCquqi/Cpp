#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;
int main(){
	string name;
	long double ave;
	int bog,cla,num,wor,chin,math,engl,tot,age,dili,hist,scie,magic,gra;
	srand(time(0));
	cout<<"信息调查中心\n---------------\n";
	cout<<"你要查询谁的信息?"<<endl;
	cin>>name;
	chin=rand()%98+2;
	math=rand()%98+2;
	engl=rand()%98+2;
	dili=rand()%98+2;
	hist=rand()%98+2;
	scie=rand()%98+2;
	bog=rand()%2+1;
	cla=rand()%5+1;
	age=rand()%98+2;
	gra=rand()%5+1;
	while (age<=60)
	age=rand()%98+2;
	magic=rand()%9+1;
	cout<<"---------------\n调研完毕,正在读取...\n\n读取完毕,正在生成随机数...\n\n生成完毕,正在创建个人档案...\n\n创建完毕。";
	cout<<name<<"的个人档案\n----------------\n姓名:"<<name<<"\n\n性别:";
	if (cla==1)
	num=rand()%34+2;
	if (cla!=1)
	num=rand()%35+2;
	if (bog==1)
	cout<<"男";
	if (bog==2)
	cout<<"女";
	cout<<"性;\n\n";
	cout<<"年龄:"<<age; 
	if (2<=age && age<10)cout<<"(年少)\n";
	else if (10<=age && age<18)cout<<"(青年)\n";
	else if (18<=age && age<65)cout<<"(成年)\n";
	else if (65<=age && age<85)cout<<"(老年)\n"; 
	else cout<<"(离谱)\n";
	cout<<"\nCP:";
	if (gra==1)cout<<"中一";
	else if(gra==2)cout<<"中二";
	else if(gra==3)cout<<"中三";
	else if(gra==4)cout<<"高一";
	else if(gra==5)cout<<"高二";
	else cout<<"高三"; 
	cout<<"("<<cla<<")班"<<num<<"号\n";
	cout<<"\n期中考试情况:\n\n";
	cout<<"语文:"<<chin<<"\n"<<endl; 
	cout<<"数学:"<<math<<"\n"<<endl; 
	cout<<"英语:"<<engl<<"\n"<<endl;
	cout<<"地理:"<<dili<<"\n"<<endl;
	cout<<"历史:"<<hist<<"\n"<<endl;
	cout<<"科学:"<<scie<<"\n"<<endl; 
	ave=(chin+math+engl+dili+hist+scie)/6;
	tot=chin+math+engl+dili+hist+scie;
	cout<<"均分:"<<ave<<"\n"<<endl;  
	cout<<"总分:"<<tot<<"\n"<<endl;
	cout<<"今日运势:"<<magic;
	if(magic==1 || magic==2)cout<<"(极差)";
	else if(magic==3 || magic==4)cout<<"(差)"; 
	else if(magic==5)cout<<"(一般)";
	else if(magic==6 || magic==7)cout<<"(不错)";
	else cout<<"(极好)";
	cout<<"\n---------------------------------\n";
	cout<<"信息加载完毕,";
	cout<<"请付费:5元";
	return 0;
}