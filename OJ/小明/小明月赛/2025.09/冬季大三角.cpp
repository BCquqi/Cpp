#include<iostream>
using namespace std;

const int N = 105;
char c[N][N];
int h,w,x[5],y[5],cur;

bool check(int x3,int y3) {return (x[2] - x[1]) * (y3 - y[2]) == (x3 - x[2]) * (y[2] - y[1]);}

int main() {
    cin >> h >> w;
    for (int i = 1;i <= h;i++)
        for (int j = 1;j <= w;j++) {
            cin >> c[i][j];
            if (c[i][j] == '*') x[++cur] = i,y[cur] = j;
        }
    bool flag = false;
    for (int i = 1;i <= h && !flag;i++)
        for (int j = 1;j <= w;j++)
            if (c[i][j] != '*' && !check(i,j)) {c[i][j] = '*'; flag = true; break;}
    for (int i = 1;i <= h;i++) {
        for (int j = 1;j <= w;j++) cout << c[i][j];
        cout << endl;
    }
    return 0;
}