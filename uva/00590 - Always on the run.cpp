#include <bits/stdc++.h>

#define FILE 	    0
#define INPUT 	    "input"
#define OUTPUT 	    "output"

#define MP 	        make_pair
#define MT 	        make_tuple
#define PB 	        push_back
#define FI 	        first
#define SE 	        second

#define MAX_CITIES 	int( 40 )
#define MAX_DAYS 	int( 1100 )
#define INF 	    LONG_MAX/10LL
#define EPS 	    int(1e-7)
#define MOD 	    int(1e7+7)
#define PI 	        acos(-1)

typedef long long ll;

using namespace std;

int nCities, kDays;
int d[ MAX_CITIES ][ MAX_CITIES ];
ll cost[ MAX_CITIES ][ MAX_CITIES ][ MAX_CITIES ];
ll dp[ MAX_CITIES ][ MAX_DAYS ];

void printAnswer( int t, ll ans ) {
    cout << "Scenario #" << t << "\n";
    if( ans >= INF ) cout << "No flight possible.\n\n";
    else cout << "The best flight costs " << ans << ".\n\n";
}

int main( ) {

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    for( int tc = 1; ( cin >> nCities >> kDays ) && ( nCities+kDays > 0 ); tc++ ) {
        for( int u = 1; u <= nCities; u++ ) {
            for( int v = 1; v <= nCities; v++ ) {
                if( u == v ) continue;
                cin >> d[ u ][ v ];
                for( int i = 1; i <= d[ u ][ v ]; i++ )
                    cin >> cost[ u ][ v ][ i ];
                cost[ u ][ v ][ 0 ] = cost[ u ][ v ][ d[ u ][ v ] ];
            }
        }
        for( int f = 1; f <= nCities; f++ ) {
            for( int k = 0; k <= kDays; k++ ) {
                dp[ f ][ k ] = INF;
            }
        }
        dp[ nCities ][ kDays ] = 0;
        for( int k = kDays-1; k >= 0; k-- ) {
            for( int f = 1; f <= nCities; f++ ) {
                for( int t = 1; t <= nCities; t++ ) {
                    if( f == t || cost[ f ][ t ][ (k+1)%d[ f ][ t ] ] == 0 ) continue;
                    dp[ f ][ k ] = min( dp[ f ][ k ], dp[ t ][ k+1 ]+cost[ f ][ t ][ (k+1)%d[ f ][ t ] ] );
                }

            }
        }
        printAnswer( tc, dp[ 1 ][ 0 ] );
    }

    return 0;
}
