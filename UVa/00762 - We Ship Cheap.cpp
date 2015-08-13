#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int( 1e3+100 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int n, id, idF, idT, t;
int p[ MAX ];
string fr, to, c[ MAX ];
map< string, int > ids;
vector< int > g[ MAX ];
bool seen[ MAX ];

int getId( string city ) {
    if( ids.count( city ) ) return ids[ city ];
    ids[ city ] = ++id;
    c[ id ] = city;
    return id;
}

void initialize( ) {
    id = 0;
    ids.clear( );
    for( int i = 0; i < MAX; i++ ) {
        g[ i ].clear( );
        c[ i ] = "";
        p[ i ] = -1;
        seen[ i ] = false;
    }
}

void rebuildPath( int cur ) {
    if( p[ cur ] == -1 ) return;
    rebuildPath( p[ cur ] );
    cout << c[ p[ cur ] ] << " " << c[ cur ] << "\n";
}

void solve( ) {
    queue< int > q;
    q.push( idF );
    seen[ idF ] = true;
    while( !q.empty( ) ) {
        int cur = q.front( ); q.pop( );
        for( int i = 0; i < ( g[ cur ].size( ) ); i++ ) {
            if( !seen[ g[ cur ][ i ] ] ) {
                seen[ g[ cur ][ i ] ] = true;
                p[ g[ cur ][ i ] ] = cur;
                q.push( g[ cur ][ i ] );
            }
        }
    }
    if( ++t > 1 ) cout << "\n";
    if( p[ idT ] == -1 ) cout << "No route\n";
    else rebuildPath( idT );
}

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( cin >> n ) {
        initialize( );
        for( int i = 0; i < n; i++ ) {
            cin >> fr >> to;
            idF = getId( fr );
            idT = getId( to );
            g[ idF ].PB( idT );
            g[ idT ].PB( idF );
        }
        cin >> fr >> to;
        idF = getId( fr );
        idT = getId( to );
        solve( );
    }

    return 0;
}
