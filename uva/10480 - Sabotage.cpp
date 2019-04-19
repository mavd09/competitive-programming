#include <bits/stdc++.h>

#define MP          make_pair
#define PB          push_back
#define FI          first
#define SE          second

#define MAX         110
#define LOG_MAX     14

#define MAX_PRIMES  1245

#define INF         ( INT_MAX )

#define MOD         1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int TAM     = 55;
const int INF_CAP = 1e9;

struct Edge {
    int to, cap, invIdx;
    Edge( ) { }
    Edge( int a, int b, int c ) : to( a ), cap( b ), invIdx( c ) { }
};

struct Network {
    
    vector< Edge > G[ TAM ];
    int from[ TAM ], n;
    bool color[ TAM ];
    
    Network( ) {
        memset( color, false, sizeof( color ) );
    }
    
    void flood( int node ) {
        if( color[ node ] ) return ;
        color[ node ] = true;
        for( auto& e : G[ node ] )
            if( e.cap > 0 )
                flood( e.to );
    }
    
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
    
    int n, m;
    
    for( int tc = 1; ( cin >> n >> m ) && ( n+m > 0 ); tc++ ) {
        Network netw;
        int source = 1, sink = 2;
        for( int i = 0, u, v, c; i < m; i++ ) {
            cin >> u >> v >> c;
            netw.addNonDirEdge( u, v, c);
        }
        netw.maxFlow( source, sink );
        netw.flood( source );
        set< pair< int, int > > ans;
        for( int u = 1; u <= n; u++ ) {
            for( auto& e : netw.G[ u ] ) {
                if( netw.color[ u ] != netw.color[ e.to ] )
                    ans.insert( MP( min( u, e.to ), max( u, e.to ) ) );
            }
        }
        for( auto& a : ans ) cout << a.FI << " " << a.SE << "\n";
        cout << "\n";
    }
    
    return 0;
    
}
