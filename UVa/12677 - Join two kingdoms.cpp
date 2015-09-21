#include <bits/stdc++.h>

#define MP   make_pair
#define PB   push_back
#define FI   first
#define SE   second

#define MAX     40100

#define INF  ( 1<<29 )

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int N, Q;
int maxDiameter, diameter[ 2 ], total[ 2 ], accum[ MAX ];
vector< int > G[ 2 ][ MAX ];
int d[ MAX ], minDist[ 2 ][ MAX ];
bool visited[ MAX ];

void initialize( ) {
    total[ 0 ] = total[ 1 ] = 0;
    for( int i = 0; i < MAX; i++ ) {
        G[ 0 ][ i ].clear( );
        G[ 1 ][ i ].clear( );
        minDist[ 0 ][ i ] = minDist[ 1 ][ i ] = 0;
        accum[ i ] = 0;
    }
}

pair< int, int > furthest( int id, int u ) {
    
    pair< int, int > ret( -1, -1 );
    memset( d, -1, sizeof( d ) );
    memset( visited, false, sizeof( visited ) );
    queue< int > q;
    q.push( u );
    d[ u ] = 0;
    visited[ u ] = true;
    
    while( !q.empty( ) ) {
        u = q.front( ); q.pop( );
        if( d[ u ] > ret.FI ) ret = MP( d[ u ], u );
        for( int i = 0, v; i < int( G[ id ][ u ].size( ) ); i++ ) {
            v = G[ id ][ u ][ i ];
            if( visited[ v ] ) continue;
            visited[ v ] = true;
            d[ v ] = d[ u ]+1;
            q.push( v );
        }
    }
    
    return ret;
    
}

void fillMinDist( int id, int u ) {
    
    memset( d, -1, sizeof( d ) );
    memset( visited, false, sizeof( visited ) );
    queue< int > q;
    q.push( u );
    d[ u ] = 0;
    visited[ u ] = true;
    
    while( !q.empty( ) ) {
        u = q.front( ); q.pop( );
        minDist[ id ][ u ] = max( minDist[ id ][ u ], d[ u ] );
        for( int i = 0, v; i < int( G[ id ][ u ].size( ) ); i++ ) {
            v = G[ id ][ u ][ i ];
            if( visited[ v ] ) continue;
            visited[ v ] = true;
            d[ v ] = d[ u ]+1;
            q.push( v );
        }
    }
    
}

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    while( cin >> N >> Q ) {
        
        initialize( );
        for( int i = 1, u, v; i < N; i++ ) {
            cin >> u >> v;
            G[ 0 ][ u ].PB( v );
            G[ 0 ][ v ].PB( u );
        }
        for( int i = 1, u, v; i < Q; i++ ) {
            cin >> u >> v;
            G[ 1 ][ u ].PB( v );
            G[ 1 ][ v ].PB( u );
        }
        
        int A, B, C, D;
        pair< int, int > tmp;
        
        A = furthest( 0, 1 ).SE;
        tmp = furthest( 0, A );
        B = tmp.SE;
        diameter[ 0 ] = tmp.FI;
        
        C = furthest( 1, 1 ).SE;
        tmp = furthest( 1, C );
        D = tmp.SE;
        diameter[ 1 ] = tmp.FI;
        
        fillMinDist( 0, A ); fillMinDist( 0, B );
        fillMinDist( 1, C ); fillMinDist( 1, D );
        
        maxDiameter = max( diameter[ 0 ], diameter[ 1 ] );
        
        sort( minDist[ 1 ]+1, minDist[ 1 ]+1+Q );
        for( int i = 1; i <= Q; i++ ) accum[ i ] = accum[ i-1 ]+minDist[ 1 ][ i ];
        
        double ans = 0.0;
        for( int i = 1; i <= N; i++ ) {
            int lo = 1, hi = Q, mi;
            while( lo <= hi ) {
                mi = ( lo+hi )/2;
                if( minDist[ 0 ][ i ]+1+minDist[ 1 ][ mi ] <= maxDiameter ) lo = mi+1;
                else                                                        hi = mi-1;
            }
            ans += double( maxDiameter*hi )+double( accum[ Q ]-accum[ hi ] )+double( minDist[ 0 ][ i ]+1 )*double( Q-hi );
        }
        ans /= double( N*Q );
        cout << fixed << setprecision( 3 ) << ans << "\n";
        
    }
    
    return 0;
    
}