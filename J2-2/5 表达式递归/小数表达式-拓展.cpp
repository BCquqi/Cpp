#include<iostream>
#include<cstring>
using namespace std;

double solve() {
	char c; int t = 0;
	double sum = 0,mul = 1; bool f = true,num = true;
	while (cin >> c) {
		if (c >= '0' && t <= '9') t = t * 10 + (c - '0');
		else {
            if (num) {
                if (f) mul *= t;
                else mul /= t;
                t = 0;
                num = false;
            }
			if (c == '*') f = true;
			else if (c == '/') f = false;
			else if (c == '+') sum += mul,mul = 1,f = true;
			else if (c == '-') sum += mul,mul = -1,f = true;
            else if (c == '(') {
                double x = solve();
                if (f) mul *= x;
                else mul /= x;
                sum += mul;
            }
            else if (c == ')') {
                if (num) {
                    if (f) mul *= t;
                    else mul /= t;
                }
                sum += mul;
                return sum;
            }
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