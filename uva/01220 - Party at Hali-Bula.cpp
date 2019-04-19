#include <bits/stdc++.h>

#define FILE    0

#define MP      make_pair
#define PB      push_back
#define FI      first
#define SE      second

#define MAX     400

#define INF     ( 1<<29 )

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int getId( int& currentId, map< string, int >& id, string& findName ) {
    if( id.count( findName ) ) return id[ findName ];
    id[ findName ] = ++currentId;
    return currentId;
}

int dp[ MAX ][ 2 ];
bool multiAns[ MAX ][ 2 ];

int go( vector< vector< int > >& G, int u, bool canUsed ) {
    int& r = dp[ u ][ canUsed ];
    if( r != -1 ) return r;
    r = canUsed;
    for( int i = 0, v; i < int( G[ u ].size( ) ); i++ ) {
        v = G[ u ][ i ];
        if( canUsed ) {
            r += go( G, v, false );
            multiAns[ u ][ canUsed ] |= multiAns[ v ][ false ];
        }
        else {
            int r1 = go( G, v, false );
            int r2 = go( G, v, true );
            r += max( r1, r2 );
            if( r1 != r2 ) {
                if( r1 > r2 ) multiAns[ u ][ canUsed ] |= multiAns[ v ][ false ];
                else          multiAns[ u ][ canUsed ] |= multiAns[ v ][ true ];
            }
            else multiAns[ u ][ canUsed ] = true;
        }
    }
    return r;
}

void solve( vector< vector< int > >& G ) {
    memset( dp, -1, sizeof( dp ) );
    memset( multiAns, false, sizeof( multiAns ) );
    go( G, 1, false );
    go( G, 1, true );
    cout << max( dp[ 1 ][ false ], dp[ 1 ][ true ] ) << " ";
    if( dp[ 1 ][ false ] != dp[ 1 ][ true ] ) {
        if( dp[ 1 ][ false ] > dp[ 1 ][ true ] )
            cout << ( multiAns[ 1 ][ false ] ? "No\n" : "Yes\n" );
        else
            cout << ( multiAns[ 1 ][ true ] ? "No\n" : "Yes\n" );
    }
    else cout << "No\n";
}

int main( ) {

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    if( FILE&1 ) freopen( "input" , "r", stdin  );
    if( FILE&2 ) freopen( "output", "w", stdout );

    int n;
    while( ( cin >> n ) && ( n > 0 ) ) {
        int currentId = 0;
        map< string, int > id;
        vector< vector< int > > G( n+2 );
        int idU, idV;
        string u, v;
        cin >> v; getId( currentId, id, v );
        for( int i = 1; i < n; i++ ) {
            cin >> u >> v;
            idU = getId( currentId, id, u );
            idV = getId( currentId, id, v );
            G[ idV ].PB( idU );
        }
        solve( G );
    }

    return 0;
}
