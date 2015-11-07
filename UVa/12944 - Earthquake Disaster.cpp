#include <bits/stdc++.h>

#define MP          make_pair
#define PB          push_back
#define FI          first
#define SE          second

#define MAX         110
#define LOG_MAX     14

#define MAX_PRIMES  1245

#define MOD         1000000007

using namespace std;

typedef long long        ll;
typedef vector< int >    vi;
typedef vector< vi >     vvi;
typedef vector< ll >     vl;
typedef vector< vl >     vvl;
typedef pair< int, int > pii;
typedef vector< pii >    vpii;
typedef pair< ll, ll >   pll;
typedef vector< pll >    vpll;

const ll INF = 1e9;

struct Edge {
    int to, invIdx;
    ll cap, cost, flow;
    Edge( ) { }
    Edge( int to, ll cap, ll cost, int invIdx ) :
        to( to ), cap( cap ), cost( cost ), invIdx( invIdx ), flow( 0 ) { }
};

struct MinCostMaxFlow {
    
    int n;
    vector< vector< Edge > > G;
    vi prv, prvId;
    vl dist, phi;
    
    MinCostMaxFlow( int n ) : n( n ), G( n ), dist( n ), phi( n ), prv( n ), prvId( n ) { }
    
    void addDirEdge( int from, int to, ll cap, ll cost ) {
        G[ from ].PB( Edge( to, cap, cost, int( G[ to ].size( ) ) ) );
        G[ to ].PB( Edge( from, 0, -cost, int( G[ from ].size( ) )-1 ) );
    }
    
    ll dijkstra( int s, int t ) {
        fill( dist.begin( ), dist.end( ), INF );
        fill( prv.begin( ), prv.end( ), -1 );
        
        int u;
        set< pair< ll, int > > Q;
        dist[ s ] = prv[ s ] = 0;
        Q.insert( MP( dist[ s ], s ) );
        
        while( !Q.empty( ) ) {
            u = ( *Q.begin( ) ).SE; Q.erase( Q.begin( ) );
            int id = -1;
            for( auto& e : G[ u ] ) {
                id++;
                if( e.cap <= 0 ) continue;
                ll cur = e.cost+phi[ u ]-phi[ e.to ];
                if( dist[ u ]+cur < dist[ e.to ] ) {
                    Q.erase( MP( dist[ e.to ], e.to ) );
                    dist[ e.to ] = dist[ u ]+cur;
                    prv[ e.to ] = u;
                    prvId[ e.to ] = id;
                    Q.insert( MP( dist[ e.to ], e.to ) );
                }
            }
        }
        
        if( prv[ t ] == -1 ) return 0;
        
        ll ret = INF;
        for( u = t; u != s; u = prv[ u ] )
            ret = min( ret, G[ prv[ u ] ][ prvId[ u ] ].cap );
        return ret;
    }
    
    pll maxFlow( int s, int t ) {
        ll totflow = 0, totcost = 0;
        while( ll amt = dijkstra( s, t ) ) {
            for( int u = t; u != s; u = prv[ u ] ) {
                G[ prv[ u ] ][ prvId[ u ] ].cap -= amt;
                G[ G[ prv[ u ] ][ prvId[ u ] ].to ][ G[ prv[ u ] ][ prvId[ u ] ].invIdx ].cap += amt;
            }
            totflow += amt;
            totcost += amt*( dist[ t ]-phi[ s ]+phi[ t ] );
            for( int u = 0; u < n; u++ ) {
                if( prv[ u ] != -1 )
                    phi[ u ] += dist[ u ];
            }
        }
        return MP( totflow, totcost );
    }
};

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    int n, m;
    
    for( int tc = 1; ( cin >> n >> m ); tc++ ) {
        MinCostMaxFlow netw( n+1 );
        int source = 0, sink = n;
        for( int i = 1, t; i < n; i++ ) {
            cin >> t;
            netw.addDirEdge( source, i, t, 0 );
        }
        for( int i = 0, u, v, t, c; i < m; i++ ) {
            cin >> u >> v >> t >> c;
            netw.addDirEdge( u, v, t, c );
            netw.addDirEdge( v, u, t, c );
        }
        pll ans = netw.maxFlow( source, sink );
        cout << ans.FI << " " << ans.SE << "\n";
    }
    
    return 0;
    
}
