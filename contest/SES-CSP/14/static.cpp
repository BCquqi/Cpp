#include<cstdio>
#define uint unsigned int
#define ull unsigned long long
using namespace std;

int main() {
    double aa,bb;
    char op;
    freopen("static.in", "r", stdin);
    freopen("static.out", "w", stdout);
    scanf("%lf%lf %c",&aa,&bb,&op);
    uint a = (uint)(aa * 256.0 + 0.5);
    uint b = (uint)(bb * 256.0 + 0.5);
    uint res;
    switch (op) {
        case '+':
            res = a + b;
            break;
        case '-':
            res = a - b;
            break;
        case '*':
            res = (uint)(((ull)a * b + 128) >> 8);
            break;
        case '/':
            res = (uint)((((ull)a << 8) + b / 2) / b);
            break;
    }
    printf("%.8lf %.8lf\n%.8lf\n", (double)a / 256.0, (double)b / 256.0, (double)res / 256.0);
    return 0;
}