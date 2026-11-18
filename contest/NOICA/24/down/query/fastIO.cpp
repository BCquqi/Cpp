#include <iostream>

char buf[1 << 20], *p1 = buf, *p2 = buf;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) ? EOF : *p1++)

inline 
int read() {
	int x = 0; char c = getchar();
	for (; c < '0' || c > '9'; c = getchar());
	for (; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = getchar());
	return x;
}
