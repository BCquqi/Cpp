#include<iostream>
#include<stack>
using namespace std;

const int N = 3e6 + 5;
int a[N],ans[N];
stack<int> st;

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = n;i >= 1;i--) {
        while (!st.empty() && a[i] >= a[st.top()]) st.pop();
        ans[i] = (st.empty() ? 0 : st.top());
        st.push(i);
    }
    for (int i = 1;i <= n;i++) cout << ans[i] << ' ';
    return 0;
}