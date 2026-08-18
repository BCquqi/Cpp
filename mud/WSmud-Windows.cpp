#include<cstdio>
#include<iostream>
#include<unistd.h>
#include<cstdlib>
#include<windows.h>
using namespace std;

/*
颜色代号:

0 = 黑色 8 = 灰色
1 = 蓝色 9 = 淡蓝色
2 = 绿色 10 = 淡绿色
3 = 浅绿色 11 = 淡浅绿色
4 = 红色 12 = 淡红色
5 = 紫色 13 = 淡紫色
6 = 黄色 14 = 淡黄色
7 = 白色 15 = 亮白色
*/

// Windows 彩写函数 
void COLOR_PRINT(const char* s, int color)
{
 HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
 printf(s);
 SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);
}

// 测试区
void test() {
	COLOR_PRINT("欢迎登陆",4);
	printf("武神传说"); 
	sleep(5);
	system("cls");
	return ;
}

// 主函数
int main() {
	SetConsoleTitle("WSmud");
	test();
	return 0;
}
