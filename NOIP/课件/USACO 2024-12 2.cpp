#include<iostream>
using namespace std;

const int N = 1000 + 5;

int X[N][N],Y[N][N],Z[N][N]; 

int main()
{
	int x,y,z,q,n,cnt;
	cin >> n >> q;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			X[i][j] = Y[i][j] = n;
			Z[i][j] = n;
		}
	}
	
	return 0;
}
