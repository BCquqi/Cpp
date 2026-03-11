#include <bits/stdc++.h>
using namespace std;
int N, K, A[200010], minn = 1e9;
int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
		cin >> A[i];
	sort(A + 1, A + N + 1);
	for (int i = 1; i <= K + 1; ++i)
		if (A[i + N - K - 1] - A[i] <= minn)
			minn = A[i + N - K - 1] - A[i];
	cout << minn;
	return 0;
}
