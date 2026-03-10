#include<iostream>
#include<vector>
using namespace std;

const int N = 1005;
char a[N][N];
vector<pair<int,int> > pos;

int main() {
    int h,w,x1 = 1e9,x2 = 0,y1 = 1e9,y2 = 0;
    cin >> h >> w;
    for (int i = 1;i <= h;i++)
        for (int j = 1;j <= w;j++) {
            cin >> a[i][j];
            if (a[i][j] == '#') x1 = min(x1,i), x2 = max(x2,i), y1 = min(y1,j), y2 = max(y2,j);
            else if (a[i][j] == '.') pos.push_back(make_pair(i,j));
        }
    for (auto i : pos)
        if (i.first >= x1 && i.first <= x2 && i.second >= y1 && i.second <= y2) {
            cout << "No" << endl;
            return 0;
        }
    cout << "Yes" << endl;
    return 0;
}