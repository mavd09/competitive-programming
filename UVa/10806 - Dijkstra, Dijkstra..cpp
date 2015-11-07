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

struct MinCostMaxFlow {
    
    int n;
    vvl cap, flow, cost;
    vi found;
    vl dist, phi, width;
    vpii dad;
    
    MinCostMaxFlow( int n ) :
        n( n ), cap( n, vl( n ) ), flow( n, vl( n ) ), cost( n, vl( n ) ),
        found( n ), dist( n ), phi( n ), width( n ), dad( n ) { }
    
    void addDirEdge( int from, int to, ll cap, ll cost ) {
        this->cap[ from ][ to ]  = cap;
        this->cost[ from ][ to ] = cost;
    }
    
    void relax( int s, int k, ll cap, ll cost, int dir ) {
        ll val = dist[ s ]+phi[ s ]-phi[ k ]+cost;
        if( cap && val < dist[ k ] ) {
            dist[ k ]  = val;
            dad[ k ]   = MP( s, dir );
            width[ k ] = min( cap, width[ s ] );
        }
    }
    
    ll dijkstra( int s, int t ) {
        fill( found.begin( ), found.end( ), false );
        fill( dist.begin( ), dist.end( ), INF );
        fill( width.begin( ), width.end( ), 0 );
        dist[ s ] = 0;
        width[ s ] = INF;
        
        while( s != -1 ) {
            int best = -1;
            found[ s ] = true;
            for( int k = 0; k < n; k++ ) {
                if( found[ k ] ) continue;
                relax( s, k, cap[ s ][ k ]-flow[ s ][ k ], cost[ s ][ k ], 1 );
                relax( s, k, flow[ k ][ s ], -cost[ k ][ s ], -1 );
                if( best == -1 || dist[ k ] < dist[ best ] ) best = k;
            }
            s = best;
        }
        
        for( int k = 0; k < n; k++ )
            phi[ k ] = min( phi[ k ]+dist[ k ], INF );
        return width[ t ];
    }
    
    pll maxFlow( int s, int t ) {
        ll totflow = 0, totcost = 0;
        while( ll amt = dijkstra( s, t ) ) {
            totflow += amt;
            for( int x = t; x != s; x = dad[ x ].FI ) {
                if( dad[ x ].SE == 1 ) {
                    flow[ dad[ x ].FI ][ x ] += amt;
                    totcost += amt*cost[ dad[ x ].FI ][ x ];
                }
                else {
                    flow[ x ][ dad[ x ].FI ] -= amt;
                    totcost -= amt*cost[ x ][ dad[ x ].FI ];
                }
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
    
    for( int tc = 1; ( cin >> n ) && ( n > 0 ); tc++ ) {
        int source = 0, sink = n+1;
        MinCostMaxFlow mcmf( n+2 );
        cin >> m;
        for( int i = 0, u, v, c; i < m; i++ ) {
            cin >> u >> v >> c;
            mcmf.addDirEdge( u, v, 1, c );
            mcmf.addDirEdge( v, u, 1, c );
        }
        mcmf.addDirEdge( source, 1, 2, 0 );
        mcmf.addDirEdge( n, sink, 2, 0 );
        pll ans = mcmf.maxFlow( source, sink );
        if( ans.FI == 2 ) cout << ans.SE << "\n";
        else cout << "Back to jail\n";
    }
    
    return 0;
    
}
