#include<iostream>
using namespace std;

const int N = 105;
char a[N][N];

struct Node {
    int id,score;
} p[N];

int check(char x,char y) {
    if (x == y) return 0;
    if (x == 'G' && y == 'P') return -1;
    if (x == 'C' && y == 'G') return -1;
    if (x == 'P' && y == 'C') return -1;
    return 1;
}

bool cmp(Node x,Node y) {
    if (x.score != y.score) return x.score > y.score;
    return x.id < y.id;
}

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= 2 * n;i++)
        for (int j = 1;j <= m;j++)
            cin >> a[i][j];
    for (int i = 1;i <= 2 * n;i++) p[i] = {i,0};
    for (int i = 1;i <= m;i++) {
        for (int j = 1;j <= n;j++) {
            int id1 = p[2 * j - 1].id,id2 = p[2 * j].id;
            if (check(a[id1][i],a[id2][i]) == 1) p[2 * j - 1].score++;
            else if (check(a[id1][i],a[id2][i]) == -1) p[2 * j].score++;
        }
        sort(p + 1,p + 2 * n + 1,cmp);
    }
    for (int i = 1;i <= 2 * n;i++) cout << p[i].id << endl;
    return 0;
}