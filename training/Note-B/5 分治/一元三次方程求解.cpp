#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    double a,b,c,d;
    cin >> a >> b >> c >> d;
    for (double i = -100;i <= 100;i += 0.001) {
        double eps = i + 0.001;
        double m = a * i * i * i + b * i * i + c * i + d;
        double n = a * eps * eps * eps + b * eps * eps + c * eps + d;
        if (m >= 0 && n <= 0 || m <= 0 && n >= 0)
            printf("%.2lf ",(i + eps) / 2);
    }
    return 0;
}