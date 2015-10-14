#include <bits/stdc++.h>

#define MP          make_pair
#define PB          push_back
#define FI          first
#define SE          second

#define MAX         20
#define MAXT        60

#define INF         ( 1<<29 )

#define MOD         1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int TAM     = 6000;
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
    
    int k, p;
    
    for( int tc = 1; ( cin >> k >> p ) && ( k+p > 0 ); tc++ ) {
        int totalProblems = 0;
        vector< int > amountPerCategory( k );
        for( auto& cur : amountPerCategory ) cin >> cur, totalProblems += cur;
        Network netw;
        int source = 0, sink = k+p+1;
        for( int i = 1, amount; i <= p; i++ ) {
            cin >> amount;
            for( int j = 1, category; j <= amount; j++ ) {
                cin >> category;
                netw.addDirEdge( i, p+category, 1 );
            }
        }
        for( int i = 1; i <= p; i++ ) netw.addDirEdge( source, i, 1 );
        for( int i = 1; i <= k; i++ ) netw.addDirEdge( p+i, sink, amountPerCategory[ i-1 ] );
        if( netw.maxFlow( source, sink ) == totalProblems ) {
            cout << 1 << "\n";
            vector< vector< int > > ans( k );
            for( int i = 1; i <= p; i++ ) {
                for( auto& cur : netw.G[ i ] ) {
                    if( cur.cap == 0 && p < cur.to && cur.to <= p+k ) {
                        ans[ cur.to-p-1 ].PB( i );
                    }
                }
            }
            for( auto& v : ans ) {
                for( int i = 0; i < int( v.size( ) ); i++ ) {
                    if( i ) cout << " ";
                    cout << v[ i ];
                }
                cout << "\n";
            }
        }
        else cout << 0 << "\n";
    }
    
    return 0;
    
}