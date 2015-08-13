#include <bits/stdc++.h>

#define FILE 	1
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int( 1e4+100 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int r, c, q, a, b, s, t;
int parent[ MAX ], rnk[ MAX ];
bool can[ MAX ];

void initialize( ) {
    for( int i = 0; i < MAX; i++ ) {
        parent[ i ] = i;
        rnk[ i ] = 0;
        can[ i ] = true;
    }
}

int findSet( int u ) {
    if( u == parent[ u ] ) return u;
    return parent[ u ] = findSet( parent[ u ] );
}

void unionSet( int u, int v ) {
    int uRoot = findSet( u );
    int vRoot = findSet( v );
    if( uRoot == vRoot ) {
        can[ u ] = can[ v ] = false;
        return ;
    }
    if( rnk[ uRoot ] > rnk[ vRoot ] )
        parent[ vRoot ] = uRoot;
    else {
        parent[ uRoot ] = vRoot;
        if( rnk[ uRoot ] == rnk[ vRoot ] )
            rnk[ vRoot ]++;
    }
}

int main( ) {

	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );
	cout.tie( 0 );

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( ( cin >> r >> c >> q ) && ( r+c+q > 0 ) ) {
        initialize( );
        for( int i = 0; i < c; i++ ) {
            cin >> a >> b;
            unionSet( a, b );
        }
        for( int i = 0; i < q; i++ ) {
            cin >> a >> b;
            cout << ( ( can[ a ]&can[ b ] && findSet( a ) == findSet( b ) ) ? "Y\n" : "N\n" );
        }
        cout << "-\n";
    }

    return 0;
}
