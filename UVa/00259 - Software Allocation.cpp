#include <bits/stdc++.h>

#define MP          make_pair
#define PB          push_back
#define FI          first
#define SE          second

#define MAX         50020
#define LOG_MAX     14

#define MAX_PRIMES  1245

#define INF         ( INT_MAX )

#define MOD         1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

typedef long long LL;

const int TAM     = 38;
const int INF_CAP = 1e9;

struct Edge {
    int to, cap, invIdx;
    Edge( ) { }
    Edge( int a, int b, int c ) : to( a ), cap( b ), invIdx( c ) { }
};

struct Network {
    
    vector< Edge > G[ TAM ];
    int from[ TAM ], n;
    
    int maxFlow( int A, int B ) {
        int flow = 0;
        while( true ) {
            memset( from, -1, sizeof( from ) );
            
            queue< int > q;
            q.push( A );
            from[ A ] = -2;
            for( int i; !q.empty( ); q.pop( ) ) {
                i = q.front( );
                for( Edge& e : G[ i ] )
                    if( from[ e.to ] == -1 && e.cap ) {
                        from[ e.to ] = e.invIdx;
                        q.push( e.to );
                    }
            }
            
            if( from[ B ] == -1 ) break;
            
            int aug = INF_CAP;
            for( int i = B, j; i != A; i = j ) {
                j = G[ i ][ from[ i ] ].to;
                aug = min( aug, G[ j ][ G[ i ][ from[ i ] ].invIdx ].cap );
            }
            
            for( int i = B, j; i != A; i = j ) {
                j = G[ i ][ from[ i ] ].to;
                G[ j ][ G[ i ][ from[ i ] ].invIdx ].cap -= aug;
                G[ i ][ from[ i ] ].cap += aug;
            }
            
            flow += aug;
        }
        
        return flow;
    }
    
    void addNonDirEdge( int a, int b, int c ) {
        G[ a ].push_back( Edge( b, c, int( G[ b ].size( ) ) ) );
        G[ b ].push_back( Edge( a, c, int( G[ a ].size( ) )-1 ) );
    }
    
    void addDirEdge( int a, int b, int c ) {
        G[ a ].push_back( Edge( b, c, int( G[ b ].size( ) ) ) );
        G[ b ].push_back( Edge( a, 0, int( G[ a ].size( ) )-1 ) );
    }
    
};

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    string line, cur;
    
    while( !cin.eof( ) ) {
        
        Network netw;
        int source = 0, sink = 37, target = 0;
        
        for( int i = 27; i < sink; i++ ) netw.addDirEdge( i, sink, 1 );
        
        while( getline( cin, line ) ) {
            if( line == "" ) break;
            stringstream ss( line );
            ss >> cur;
            int id = cur[ 0 ]-'A'+1;
            netw.addDirEdge( source, id, cur[ 1 ]-'0' );
            target += ( cur[ 1 ]-'0' );
            ss >> cur;
            for( int i = 0; i+1 < int( cur.size( ) ); i++ )
                netw.addDirEdge( id, 27+(cur[ i ]-'0'), 1 );
        }
        
        if( netw.maxFlow( source, sink ) == target ) {
            string ans( 10, '_' );
            for( int u = 1; u <= 26; u++ ) {
                for( int i = 0; i < int( netw.G[ u ].size( ) ); i++ ) {
                    int v = netw.G[ u ][ i ].to;
                    if( 27 <= v && v < sink && netw.G[ u ][ i ].cap == 0 ) {
                        ans[ v-27 ] = 'A'+u-1;
                    }
                }
            }
            cout << ans << "\n";
        }
        else cout << "!\n";
        
    }
    
    return 0;
    
}