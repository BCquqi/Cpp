#include<iostream>
using namespace std;
int main() {
	int num[10] = { 1,2,3 };
	for (auto v : num)
		cout << v << " ";
	cout << endl;
	return 0;
}
