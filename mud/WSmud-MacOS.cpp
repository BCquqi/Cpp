#include<cstdio>
#include<iostream>
#include<unistd.h>
#include<cstdlib>
#include<windows.h>
using namespace std;

// 颜色定义
#define COLOR_DEFAULT       "\033[0m"
#define COLOR_Blue          "\033[0;34m"
#define COLOR_Green         "\033[0;32m"
#define COLOR_Red           "\033[0;31m"
#define COLOR_Yellow        "\033[0;33m"
#define COLOR_White         "\033[0;37m"
#define COLOR_Cyan          "\033[0;36m"
#define COLOR_Magenta       "\033[0;35m"
#define COLOR_BrightBlue    "\033[1;34m"
#define COLOR_BrightGreen   "\033[1;32m"
#define COLOR_BrightRed     "\033[1;31m"
#define COLOR_BrightYellow  "\033[1;33m"
#define COLOR_BrightWhite   "\033[1;37m"
#define COLOR_BrightCyan    "\033[1;36m"
#define COLOR_BrightMagenta "\033[1;35m"

// 测试区
void test() {
	printf("Hello, ");
	printf(COLOR_BrightBlue "cookie" COLOR_DEFAULT);
	sleep(5);
	system("clear");
	return ;
}

// 主函数
int main() {
	SetConsoleTitle("WSmud");
	test();
	return 0;
}
