#include <bits/stdc++.h>

#define FILE 	1
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAXN 	int( 1e4+10 )
#define INF 	double( 1e17 )
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)
#define LIM     1.5

typedef long long ll;

using namespace std;

int n;
double w, h, d;
string line;

double x[ MAXN ], y[ MAXN ];
double minDist[ MAXN ];
bool seen[ MAXN ];
vector< pair< int, double > > G[ MAXN ];

struct State {
    double curD;
    int node;
    State( ) { }
    State( double curD, int node ) : curD( curD ), node( node ) { }
}cur;

struct cmp {
    bool operator ( ) ( const State& a, const State& b ) {
        return a.curD > b.curD;
    }
};

double getDist( int a, int b ) {
    return sqrt( ( x[a]-x[b] )*( x[a]-x[b] ) + ( y[a]-y[b] )*( y[a]-y[b] ) );
}

void initialize( ) {
    for( int i = 0; i <= n+1; i++) {
        G[ i ].clear( );
        minDist[ i ] = INF;
        seen[ i ] = false;
    }
}

string dijkstra( ) {
    priority_queue< State, vector< State >, cmp > Q;
    Q.push( State( 0.0, 0 ) );
    minDist[ 0 ] = 0.0;
    while( !Q.empty( ) ) {
        cur = Q.top( ); Q.pop( );
        if( seen[ cur.node ] ) continue;
        if( cur.node == 1 ) {
            if( cur.curD <= d ) return "I am lucky!";
            break;
        }
        seen[ cur.node ] = true;
        for( int i = 0; i < int( G[ cur.node ].size( ) ); i++ ) {
            int neighbor = G[ cur.node ][ i ].FI;
            double cost  = G[ cur.node ][ i ].SE;
            if( !seen[ neighbor ] && minDist[ cur.node ]+cost < minDist[ neighbor ] ) {
                minDist[ neighbor ] = minDist[ cur.node ]+cost;
                Q.push( State( minDist[ neighbor ], neighbor  ) );
            }
        }
    }
    return "Boom!";
}

int main( ) {

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

	x[ 0 ] = y[ 0 ] = 0.0;

    while( getline( cin, line ) && line != "*" ) {
        stringstream ss( line );
        ss >> w >> h;
        cin >> n;
        initialize( );
        x[ 1 ] = w;
        y[ 1 ] = h;
        for( int i = 1; i <= n+1; i++ ) {
            if( i > 1 ) cin >> x[ i ] >> y[ i ];
            for( int j = 0; j < i; j++ ) {
                d = getDist( j, i );
                if( d <= LIM ) {
                    G[ i ].PB( MP( j, d ) );
                    G[ j ].PB( MP( i, d ) );
                }
            }
        }
        cin >> d;
        cin.ignore( );
        cout << dijkstra( ) << "\n";
    }

    return 0;
}
