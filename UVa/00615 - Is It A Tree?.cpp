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

int dfs( map< int, vector< int > >& G, set< int >& used, int u ) {
    int ret = 1;
    used.insert( u );
    for( auto& v : G[ u ] ) {
        if( !used.count( v ) )
            ret += dfs( G, used, v );
    }
    return ret;
}

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    int u, v;
    
    for( int tc = 1; ( cin >> u >> v ) && !( u == -1 && v == -1 ); tc++ ) {
        if( u == 0 && v == 0 ) {
            cout << "Case " << tc << " is a tree.\n";
            continue;
        }
        map< int, vector< int > > G;
        set< int > used, inDeg, nodes;
        int cntEdges = 0, cntNodes = 0;
        do {
            G[ u ].PB( v );
            nodes.insert( u );
            nodes.insert( v );
            inDeg.insert( v );
            cntEdges++;
        } while( ( cin >> u >> v ) && !( u == 0 && v == 0 ) );
        cntNodes = int( nodes.size( ) );
        for( auto& u : inDeg ) nodes.erase( u );
        if( cntNodes-1 == cntEdges && nodes.size( ) == 1 && dfs( G, used, *nodes.begin( ) ) == cntNodes )
            cout << "Case " << tc << " is a tree.\n";
        else cout << "Case " << tc << " is not a tree.\n";
    }
    
    return 0;
    
}
