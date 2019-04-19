#include <bits/stdc++.h>

using namespace std;

const int MOD = 10;
int t, m;
int mat[2][2];
int ans[2][2];

int fast_pow( int e ){
	mat[0][0] = 1; mat[0][1] = 1; mat[1][0] = 1; mat[1][1] = 0;
	ans[0][0] = 1; ans[0][1] = 0; ans[1][0] = 0; ans[1][1] = 1;
	while( e ){
		if( e&1 ){
			int a = (ans[0][0]*mat[0][0] + ans[0][1]*mat[1][0]) % MOD;
			int b = (ans[0][0]*mat[0][1] + ans[0][1]*mat[1][1]) % MOD;
			int c = (ans[1][0]*mat[0][0] + ans[1][1]*mat[1][0]) % MOD;
			int d = (ans[1][0]*mat[0][1] + ans[1][1]*mat[1][1]) % MOD;
			ans[0][0] = a; ans[0][1] = b; ans[1][0] = c; ans[1][1] = d;
		}
		int a = (mat[0][0]*mat[0][0] + mat[0][1]*mat[1][0]) % MOD;
		int b = (mat[0][0]*mat[0][1] + mat[0][1]*mat[1][1]) % MOD;
		int c = (mat[1][0]*mat[0][0] + mat[1][1]*mat[1][0]) % MOD;
		int d = (mat[1][0]*mat[0][1] + mat[1][1]*mat[1][1]) % MOD;
		mat[0][0] = a; mat[0][1] = b; mat[1][0] = c; mat[1][1] = d;
		e >>= 1;
	}
}

int fibo( int e ){
	int cur[] = {1, 0};
	fast_pow( e );
	return ans[ 0 ][ 0 ];
}

int main(){
	cin >> t;

	while( t-- ){
		cin >> m;
		cout << fibo( m ) << endl;
	}

	return 0;
}