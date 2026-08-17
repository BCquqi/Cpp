#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 105;
string f[N][N];
int cpy[1005],cpy1[1005],cpy2[1005];

string mul(string a,int b) {
    string c = "";
    int len = a.size();
    memset(cpy,0,sizeof cpy);
    for (int i = len - 1;i >= 0;i--) cpy[len - i - 1] = a[i] - '0';
    int tmp = 0;
    for (int i = 0;i < len;i++) cpy[i] = cpy[i] * b + tmp, tmp = cpy[i] / 10, cpy[i] %= 10;
    while (tmp) cpy[len++] = tmp % 10,tmp /= 10;
    while (len) c += cpy[--len] + '0';
    return c;
}

string add(string a,string b) {
    string c = "";
    memset(cpy1,0,sizeof cpy1);
    memset(cpy2,0,sizeof cpy2);
    int len = max(a.size(), b.size()),lena = a.size(),lenb = b.size();
    for (int i = 0;i < lena;i++) cpy1[lena - i - 1] = a[i] - '0';
    for (int i = 0;i < lenb;i++) cpy2[lenb - i - 1] = b[i] - '0';
    for (int i = 0; i < len;i++)
        cpy1[i] += cpy2[i],cpy1[i + 1] += cpy1[i] / 10,cpy1[i] %= 10;
    if (cpy1[len]) len++;
    for (int i = len - 1;i >= 0;i--) c += cpy1[i] + '0';
    return c;
}

int main() {
    int n,m;
    for (int i = 1;i <= 100;i++) f[i][1] = "1";
    for (int i = 2;i <= 100;i++)
        for (int j = 1;j <= i;j++)
            f[i][j] = add(f[i - 1][j - 1],mul(f[i - 1][j],j));
    while (cin >> n >> m) {
        if (n < m) cout << 0 << endl;
        else cout << f[n][m] << endl;
    }
    return 0;
}