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

int nTest, c, y[ 2 ], diff;
bool can;

int main( ) {

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    cin >> nTest;
    for( int tc = 0; nTest--; tc++ ) {
        cin >> c;
        can = true;
        if( c-- ) {
            cin >> y[ 0 ] >> y[ 1 ];
            diff = y[ 0 ]-y[ 1 ];
            while( c-- ) {
                cin >> y[ 0 ] >> y[ 1 ];
                can &= ( diff == ( y[ 0 ]-y[ 1 ] ) );
            }
        }
        if( tc ) cout << "\n";
        cout << ( can ? "yes\n" : "no\n" );
    }

    return 0;
}
