#include <bits/stdc++.h>

#define MP          make_pair
#define PB          push_back
#define FI          first
#define SE          second

#define MAX         10100
#define LOG_MAX     14

#define COST        50

#define INF         ( 10000 )

#define MOD         1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n, m, dt;
int SCC_D[ MAX ], SCC_L[ MAX ], SCC_P[ MAX ];
int DSU_P[ MAX ];
int LCA_A[ MAX ][ LOG_MAX ], LCA_D[ MAX ], LCA_P[ MAX ];
int idComponent[ MAX ], components;
bool visited[ MAX ];
vector< int > G[ MAX ], NG[ MAX ];

void initialize( ) {
    for( int i = 0; i < n; i++ ) {
        G[ i ].clear( );
        NG[ i ].clear( );
        idComponent[ i ] = -1;
        
        SCC_D[ i ] = -1;
        SCC_P[ i ] = -1;
        SCC_L[ i ] = -1;
        
        DSU_P[ i ] = i;
        
        LCA_D[ i ] = -1;
        LCA_P[ i ] = -1;
    }
    components = dt = 0;
}

int findSet( int x ) {
    if( x == DSU_P[ x ] ) return x;
    return DSU_P[ x ] =  findSet( DSU_P[ x ] );
}

void unionSet( int x, int y ) {
    int xRoot = findSet( x );
    int yRoot = findSet( y );
    if( xRoot == yRoot ) return ;
    DSU_P[ yRoot ] = xRoot;
}

void bridgeUtil( int u ) {
    visited[ u ] = true;
    SCC_D[ u ] = SCC_L[ u ] = ++dt;
    for( auto& v : G[ u ] ) {
        if( !visited[ v ] ) {
            SCC_P[ v ] = u;
            bridgeUtil( v );
            SCC_L[ u ] = min( SCC_L[ u ], SCC_L[ v ] );
            if( SCC_L[ v ] > SCC_D[ u ] )
                unionSet( u, v );
        }
        else if( v != SCC_P[ u ] )
            SCC_L[ u ] = min( SCC_L[ u ], SCC_D[ v ] );
    }
}

void bridge( ) {
    memset( visited, false, sizeof( visited ) );
    bridgeUtil( 0 );
}

void mark( int u ) {
    idComponent[ u ] = components;
    visited[ u ] = true;
    for( auto& v : G[ u ] ) {
        if( visited[ v ] ) continue;
        if( findSet( u ) == findSet( v ) ) continue;
        mark( v );
    }
}

void buildNewGraph( ) {
    memset( visited, false, sizeof( visited ) );
    bridge( );
    memset( visited, false, sizeof( visited ) );
    for( int i = 0; i < n; i++ ) {
        if( !visited[ i ] ) {
            mark( i );
            ++components;
        }
    }
    for( int u = 0; u < n; u++ ) {
        for( auto& v : G[ u ] ) {
            if( idComponent[ u ] == idComponent[ v ] ) continue;
            NG[ idComponent[ u ] ].PB( idComponent[ v ] );
            NG[ idComponent[ v ] ].PB( idComponent[ u ] );
        }
    }
    for( int u = 0; u < components; u++ ) {
        sort( NG[ u ].begin( ), NG[ u ].end( ) );
        NG[ u ].resize( distance( NG[ u ].begin( ), unique( NG[ u ].begin( ), NG[ u ].end( ) ) ) );
    }
}

void dfs( int u, int d ) {
    visited[ u ] = true;
    LCA_D[ u ] = d;
    for( auto& v : NG[ u ] ) {
        if( visited[ v ] ) continue;
        dfs( v, d+1 );
        LCA_P[ v ] = u;
    }
}

void buildLCA( ) {
    memset( visited, false, sizeof( visited ) );
    LCA_P[ 0 ] = 0;
    dfs( 0, 0 );
    for( int i = 0; i < components; i++ ) LCA_A[ i ][ 0 ] = LCA_P[ i ];
    for( int j = 0; j+1 < LOG_MAX; j++ )
        for( int i = 0; i < components; i++ )
            LCA_A[ i ][ j+1 ] = LCA_A[ LCA_A[ i ][ j ] ][ j ];
}

int query( int a, int b ) {
    a = idComponent[ a ]; b = idComponent[ b ];
    int _a = a, _b = b;
    if( a == b ) return 0;
    if( LCA_D[ a ] > LCA_D[ b ] ) swap( a, b );
    for( int i = LOG_MAX-1; i >= 0; i-- )
        if( LCA_D[ a ] <= LCA_D[ LCA_A[ b ][ i ] ] )
            b = LCA_A[ b ][ i ];
    if( a == b ) return abs( ( LCA_D[ _b ]-LCA_D[ _a ] )*COST );
    for( int i = LOG_MAX-1; i >= 0; i-- ) {
        if( LCA_A[ a ][ i ] != LCA_A[ b ][ i ] ) {
            a = LCA_A[ a ][ i ];
            b = LCA_A[ b ][ i ];
        }
    }
    return abs( ( LCA_D[ _b ]+LCA_D[ _a ]-2*LCA_D[ LCA_A[ a ][ 0 ] ] )*COST );
}

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    for( int tc = 1; ( cin >> n >> m ) && ( n+m > 0 ); tc++ ) {
        initialize( );
        for( int i = 0, u, v; i < m; i++ ) {
            cin >> u >> v;
            u--; v--;
            G[ u ].PB( v );
            G[ v ].PB( u );
        }
        buildNewGraph( );
        buildLCA( );
        if( tc > 1 ) cout << "\n";
        cout << "Case #" << tc << ":\n";
        int nQueries;
        cin >> nQueries;
        for( int i = 0, u, v; i < nQueries; i++ ) {
            cin >> u >> v;
            u--; v--;
            cout << query( u, v ) << "\n";
        }
    }
    
    return 0;
    
}