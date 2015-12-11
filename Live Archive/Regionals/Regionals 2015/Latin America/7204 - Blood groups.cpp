#include <bits/stdc++.h>

#define MP          make_pair
#define PB          push_back
#define FI          first
#define SE          second

#define MAX         1000
//#define LOG_MAX     14

#define MAX_PRIMES  1245

#define INF         ( INT_MAX )

#define MOD         1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

struct Edge {
    int from, to, cap, flow, index;
    Edge( int from, int to, int cap, int flow, int index ) :
    from( from ), to( to ), cap( cap ), flow( flow ), index( index ) { }
};

struct Network {
    
    int n;
    vector< vector< Edge > > G;
    vector< ll > excess;
    vector< int > dist, active, count;
    queue< int > Q;
    
    Network( int n ) : n( n ), G( n ), excess( n ), dist( n ), active( n ), count( 2*n ) { }
    
    void addDirEdge( int from, int to, int cap ) {
        G[ from ].PB( Edge( from, to, cap, 0, int( G[ to ].size( ) ) ) );
        if( from == to ) G[ from ].back( ).index++;
        G[ to ].PB( Edge( to, from, 0, 0, int( G[ from ].size( ) )-1 ) );
    }
    
    void Enqueue( int v ) {
        if( !active[ v ] && excess[ v ] > 0 ) {
            active[ v ] = true;
            Q.push( v );
        }
    }
    
    void Push( Edge &e ) {
        int amt = int( min( excess[ e.from ], ll( e.cap - e.flow ) ) );
        if( dist[ e.from ] <= dist[ e.to ] || amt == 0 ) return ;
        e.flow += amt;
        G[ e.to ][ e.index ].flow -= amt;
        excess[ e.to ] += amt;
        excess[ e.from ] -= amt;
        Enqueue( e.to );
    }
    
    void Gap( int k ) {
        for( int v = 0; v < n; v++ ) {
            if( dist[ v ] < k ) continue;
            count[ dist[ v ] ]--;
            dist[ v ] = max( dist[ v ], n+1 );
            count[ dist[ v ] ]++;
            Enqueue( v );
        }
    }
    
    void Relabel( int v ) {
        count[ dist[ v ] ]--;
        dist[ v ] = 2*n;
        for( int i = 0; i < int( G[ v ].size( ) ); i++ )
            if( G[ v ][ i ].cap-G[ v ][ i ].flow > 0 )
                dist[ v ] = min( dist[ v ], dist[ G[ v ][ i ].to ]+1 );
        count[ dist[ v ] ]++;
        Enqueue( v );
    }
    
    void Discharge( int v ) {
        for( int i = 0; excess[ v ] > 0 && i < int( G[ v ].size( ) ); i++ )
            Push( G[ v ][ i ]);
        if( excess[ v ] > 0 ) {
            if( count[ dist[ v ] ] == 1 )
                Gap( dist[ v ] );
            else
                Relabel( v );
        }
    }
    
    ll maxFlow( int s, int t ) {
        count[ 0 ] = n-1;
        count[ n ] = 1;
        dist[ s ] = n;
        active[ s ] = active[ t ] = true;
        for( int i = 0; i < int( G[ s ].size( ) ); i++ ) {
            excess[ s ] += G[ s ][ i ].cap;
            Push( G[ s ][ i ] );
        }
        
        while( !Q.empty( ) ) {
            int v = Q.front( );
            Q.pop( );
            active[ v ] = false;
            Discharge( v );
        }
        
        ll totflow = 0;
        for (int i = 0; i < int( G[ s ].size( ) ); i++ )
            totflow += G[ s ][ i ].flow;
        return totflow;
    }
};

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    int n, q;
    
    while( cin >> n >> q ) {
        vector< vector< int > > b;
        for( int i = 0, t; i < n; i++ ) {
            cin >> t;
            b.PB( vector< int >( t ) );
            for( auto& e : b[ i ] ) cin >> e;
            if( t != n ) b[ i ].PB( 0 );
        }
        int source = 2*n+1, auxSink = 2*n+2, sink = 2*n+3;
        for( int t; q--; ) {
            Network netw( 2*n+4 );
            cin >> t;
            vector< int > c( t );
            for( auto& e : c ) {
                cin >> e;
                netw.addDirEdge( n+e, sink, 1 );
                netw.addDirEdge( n+e, auxSink, n-t );
            }
            netw.addDirEdge( auxSink, sink, n-t );
            if( t != n ) netw.addDirEdge( n+0, auxSink, n-t );
            for( int i = 0; i < n; i++ ) {
                netw.addDirEdge( source, i, 1 );
                for( auto& e : b[ i ] ) {
                    netw.addDirEdge( i, n+e, 1 );
                }
            }
            if( netw.maxFlow( source, sink ) == n ) cout << "Y\n";
            else cout << "N\n";
        }
    }
    
    return 0;
}