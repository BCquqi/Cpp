#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int n,comb[2005][2005];
const int mod = 1e9 + 7;

int main(){
	int n;
	cin >> n;
	for (int i = 0;i <= n;i++)
	{
		comb[i][0] = 1;
		for (int j = 1;j <= i;j++)
			comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
	}
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            printf("%d ", comb[i][j]);
        }
        printf("\n");
    }
	return 0;
}