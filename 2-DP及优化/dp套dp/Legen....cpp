#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 205;
int a[N];
struct Matrix {long long a[N][N];} mat,res;
int ch[N][26],id = 1,fail[N];
long long val[N];
string s[N];

void insert(string s,int w) {
    int x = 1;
    for (auto c : s) {
        int i = c - 'a';
        if (!ch[x][i]) ch[x][i] = ++id;
        x = ch[x][i];
    }
    val[x] += w;
}

Matrix operator *(const Matrix &x,const Matrix &y) {
    Matrix ret;
    for (int i = 1;i <= id;i++)
        for (int j = 1;j <= id;j++) ret.a[i][j] = -1e18;
    for (int i = 1;i <= id;i++)
        for (int k = 1;k <= id;k++)
            if (x.a[i][k] > -1e17)
                for (int j = 1;j <= id;j++)
                    if (y.a[k][j] > -1e17)
                        ret.a[i][j] = max(ret.a[i][j], x.a[i][k] + y.a[k][j]);
    return ret;
}

int main() {
    int n;
    long long l;
    cin >> n >> l;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++) {
        cin >> s[i];
        insert(s[i],a[i]);
    }
    queue<int> q;
    for (int c = 0;c < 26;c++) {
        if (ch[1][c]) fail[ch[1][c]] = 1, q.push(ch[1][c]);
        else ch[1][c] = 1;
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        val[u] += val[fail[u]];
        for (int c = 0;c < 26;c++) {
            int v = ch[u][c];
            if (v) fail[v] = ch[fail[u]][c], q.push(v);
            else ch[u][c] = ch[fail[u]][c];
        }
    }
    for (int i = 1;i <= id;i++)
        for (int j = 1;j <= id;j++) mat.a[i][j] = -1e18;
    for (int i = 1;i <= id;i++)
        for (int c = 0;c < 26;c++) {
            int j = ch[i][c];
            mat.a[i][j] = max(mat.a[i][j],val[j]);
        }
    for (int i = 1;i <= id;i++)
        for (int j = 1;j <= id;j++)
            res.a[i][j] = (i == j) ? 0 : -1e18;
    long long tmp = l;
    while (tmp) {
        if (tmp & 1) res = res * mat;
        mat = mat * mat, tmp >>= 1;
    }
    long long ans = 0;
    for (int i = 1;i <= id;i++) ans = max(ans,res.a[1][i]);
    cout << ans << endl;
    return 0;
}