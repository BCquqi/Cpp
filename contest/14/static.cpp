#include<iostream>
#include<iomanip>
using namespace std;

int main() {
    freopen("static.in","r",stdin);
    freopen("static.out","w",stdout);
    double a,b;
    cin >> a >> b;
    cout << fixed << setprecision(8) << a << ' ' << b << endl;
    char op;
    cin >> op;
    double res;
    if (op == '+') res = a + b;
    else if (op == '-') res = a - b;
    else if (op == '*') res = a * b;
    else res = a / b;
    cout << fixed << setprecision(8) << res << endl;
    return 0;
}