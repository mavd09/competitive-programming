#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int( 1e6+10 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int a[ MAX ], ans[ MAX ];

bool isPalindrome( int sz ) {
    bool ans = true;
    for( int i = 0; i < sz/2 && ans; i++ ) ans &= ( a[ i ] == a[ sz-i-1 ] );
    return ans;
}

bool isValid( int n, int b ) {
    if( b <= 1 ) return false;
    int sz = 0;
    while( n ) {
        a[ sz++ ] = n%b;
        n /= b;
    }
    return isPalindrome( sz );
}

int solve( int n ) {
    int ans = INF;
    if( isValid( n, n-1 ) ) ans = n-1;
    for( int b = 2; b*b <= 5*n; b++ ) {
        if( isValid( n, b ) )
            ans = min( ans, b );
        if( isValid( n, n/b-1 ) )
            ans = min( ans, n/b-1 );
    }
    return ans == INF ? 0 : ans;
}

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    int n, b;
    while( scanf( "%d", &n ) != EOF ) printf( "%d\n", solve( n ) );

    return 0;
}
