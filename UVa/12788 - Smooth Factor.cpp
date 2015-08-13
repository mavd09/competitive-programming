#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int( 1e5+10 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int n, ans, a[ MAX ];
vector< int > s;

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( cin >> n ) {
        for( int i = 1; i <= n; i++ ) cin >> a[ i ];

        s.clear( );
        ans = 0;
        s.PB( 1 );
        for( int i = 2; i <= n; i++ )
            if( a[ i-1 ] > a[ i ] )
                s.PB( i );
        s.PB( n+1 );

        if( int( s.size( ) ) <= 3 ) ans = n;
        else {
            for( int i = 0; i+2 < int( s.size( ) ); i++ )
                ans = max( ans, s[ i+2 ]-s[ i ] );
        }

        cout << ans << "\n";
    }

    return 0;
}
