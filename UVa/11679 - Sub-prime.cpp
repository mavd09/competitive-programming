#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int( 30 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int b, n, r[ MAX ];

int main( ) {

	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );
	cout.tie( 0 );

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    for( int tc = 1; ( cin >> b >> n ) && ( b+n > 0 ); tc++ ) {
        for( int i = 1; i <= b; i++ ) cin >> r[ i ];
        for( int i = 1, d, c, v; i <= n; i++ ) {
            cin >> d >> c >> v;
            r[ d ] -= v;
            r[ c ] += v;
        }
        bool can = true;
        for( int i = 1; i <= b; i++ ) can &= ( r[ i ] >= 0 );
        cout << ( can ? "S\n": "N\n" );
    }

    return 0;
}
