#include<iostream>
#include<cstring>
using namespace std;

double solve() {
	char c; int t = 0;
	double sum = 0,mul = 1; bool f = true;
	while (cin >> c) {
		if (c >= '0' && t <= '9') t = t * 10 + (c - '0');
		else {
			if (f) mul *= t;
			else mul /= t;
			t = 0;
			if (c == '*') f = 1;
			else if (c == '/') f = 0;
			else if (c == '+') sum += mul,mul = 1,f = 1;
			else if (c == '-') sum += mul,mul = -1,f = 1;
		}
	}
	if (f) mul *= t;
	else mul /= t;
	sum += mul;
	return sum;
}

int main() {
	printf("%.3lf",solve());
	return 0;
}