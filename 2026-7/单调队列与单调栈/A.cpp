#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;

const int N = 1e6 + 5;
int a[N];

deque<int> qmax,qmin;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,k;
    cin >> n >> k;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++) {
        while (!qmin.empty() && qmin.front() + k <= i) qmin.pop_front();
        while (!qmin.empty() && a[qmin.back()] >= a[i]) qmin.pop_back();
        qmin.push_back(i);
        if (i >= k) cout << a[qmin.front()] << ' ';
    }
    cout << endl;
    for (int i = 1;i <= n;i++) {
        while (!qmax.empty() && qmax.front() + k <= i) qmax.pop_front();
        while (!qmax.empty() && a[qmax.back()] <= a[i]) qmax.pop_back();
        qmax.push_back(i);
        if (i >= k) cout << a[qmax.front()] << ' ';
    }
    return 0;
}