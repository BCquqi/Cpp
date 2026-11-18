#include<iostream>
using namespace std;

const int N = 1e5 + 5;
int v[N],w[N];

int main() {
    int n;
    long long sumv = 0,sumw = 0;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> v[i];
        sumv += v[i];
    }
    for (int i = 1;i <= n;i++) {
        cin >> w[i];
        sumw += w[i];
    }
    cout << 1.00 * sumw / sumv << endl; 
    return 0;
}