#include<iostream>
using namespace std;

bool flag[10];
int plan[10];
int a,b,c;
bool valid = false;

void dfs(int step) {
    if (step > 9) {
        int x = plan[1] * 100 + plan[2] * 10 + plan[3],
        y = plan[4] * 100 + plan[5] * 10 + plan[6],
        z = plan[7] * 100 + plan[8] * 10 + plan[9];
        if (x * b * c == y * a * c && y * a * c == z * a * b) {
            cout << x << ' ' << y << ' ' << z << endl;
            valid = true;
        }
        return ;
    }
    for (int i = 1;i <= 9;i++) {
        if (flag[i]) continue;
        flag[i] = true,plan[step] = i;
        dfs(step + 1);
        flag[i] = false,plan[step] = 0;
    }
}

int main() {
    cin >> a >> b >> c;
    dfs(1);
    if (!valid) cout << "No!!!" << endl;
    return 0;
}