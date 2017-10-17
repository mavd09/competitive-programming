#include <bits/stdc++.h>

const int MAXN = 2501;
using namespace std;
int ac[ MAXN ][ MAXN ];

int t, n, m;

bool check( int len ){
	int i2, j2;
	for( int i = 1; i + len - 1 <= n; ++i ){
		for( int j = 1; j + len - 1 <= m; ++j ){
			i2 = i + len - 1;
			j2 = j + len - 1;
			if( ac[ i2 ][ j2 ] - ac[ i2 ][ j-1 ] - ac[ i-1 ][ j2 ] + ac[ i-1 ][ j-1 ] >= len ) return false;
		}
	}
	return true;
}

int main(){
	scanf( "%d", &t );
	int cnt1, cnt2;
	char c;
	bool flag;
	while( t-- ){
		scanf( "%d%d", &n, &m );
		cnt1 = 0, cnt2 = 0;
		for( int i = 1; i <= n; ++i ){
			for( int j = 1; j <= m; ++j ){
				scanf( " %c", &c );
				if( c == '1' ) ++cnt1;
				else if( c == '2' ) ++cnt2;
				ac[ i ][ j ] = ac[ i-1 ][ j ] + ac[ i ][ j-1 ] - ac[ i-1 ][ j-1 ] + (c != '.');
			}
		}

		if( cnt1 != cnt2 && cnt1 != cnt2+1 ){
			puts( "NO" );
		}
		else{
			flag = true;
			for( int l = 3; l <= min(n, m) && flag; ++l ){
				if( !check( l ) ){
					puts( "NO" );
					flag = false;
				}
			}
			if( flag ) puts( "YES" );
		}
	}

	return 0;
}