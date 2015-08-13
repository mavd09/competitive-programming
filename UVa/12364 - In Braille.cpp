#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int(1e7+10)
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

const string braille[ ] = { ".*", "*.", "*.", "**", "**", "*.", "**", "**", "*.", ".*",
                            "**", "..", "*.", "..", ".*", ".*", "*.", "**", "**", "*.",
                            "..", "..", "..", "..", "..", "..", "..", "..", "..", ".." };

int n;
char op;
string msg[ 3 ], ans[ 3 ];

int main( ) {

	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );
	cout.tie( 0 );

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( ( cin >> n ) && ( n > 0 ) ) {
        cin >> op;
        ans[ 0 ] = ans[ 1 ] = ans[ 2 ] = "";
        if( op == 'S' ) {
            cin >> msg[ 0 ];
            for( int i = 0; i < 3; i++ ) {
                for( int j = 0; j < int( msg[ 0 ].size( ) ); j++ ) {
                    if( j ) ans[ i ] += " ";
                    ans[ i ] += braille[ i*10+( msg[ 0 ][ j ]-'0' ) ];
                }
            }
            cout << ans[ 0 ] << "\n" << ans[ 1 ] << "\n" << ans[ 2 ] << "\n";
        }
        else {
            cin.ignore( );
            for( int i = 0; i < 3; i++ ) getline( cin, msg[ i ] );
            for( int i = 0; i < n; i++ ) {
                for( int j = 0; j < 10; j++ ) {
                    if( ( string( 1, msg[ 0 ][ i*3 ] )+string( 1, msg[ 0 ][ i*3+1 ] ) ) == braille[ j ]    &&
                        ( string( 1, msg[ 1 ][ i*3 ] )+string( 1, msg[ 1 ][ i*3+1 ] ) ) == braille[ 10+j ] &&
                        ( string( 1, msg[ 2 ][ i*3 ] )+string( 1, msg[ 2 ][ i*3+1 ] ) ) == braille[ 20+j ] ) {
                            ans[ 0 ] += ( j+'0' );
                            break;
                        }
                }
            }
            cout << ans[ 0 ] << "\n";
        }
    }

    return 0;
}
