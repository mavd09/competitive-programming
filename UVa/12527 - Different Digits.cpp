#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int( 5123 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int n, m;
int ans[ MAX ];

bool valid( int num ) {
    int cntDigits = 0;
    set< int > digits;
    while( num ) {
        digits.insert( num%10 );
        cntDigits++;
        num /= 10;
    }
    return cntDigits == int( digits.size( ) );
}

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    for( int i = 1; i < MAX; i++) ans[ i ] = ans[ i-1 ]+valid( i );
    while( scanf( "%d %d", &n, &m ) != EOF ) printf( "%d\n", ans[ m ]-ans[ n-1 ] );

    return 0;
}
