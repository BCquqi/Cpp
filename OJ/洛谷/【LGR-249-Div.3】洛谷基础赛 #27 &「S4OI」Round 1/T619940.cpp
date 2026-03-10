#include<iostream>
using namespace std;

const int N = 5e5 + 5;
int t[N][3];

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        t[N][1] = a * b,t[N][2] = c * a * (b - 1);
    }
    return 0;
}