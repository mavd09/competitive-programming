#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int( 1e5+1000 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

struct Tuple {
    int n, z, p;
    Tuple( ) { }
    Tuple( int n, int z, int p ) : n( n ), z( z ), p( p ) { }
};
Tuple operator + ( Tuple a, Tuple b ) { return Tuple( a.n+b.n, a.z+b.z, a.p+b.p ); }

int N, K, F, T;
char Op;
int X[ MAX ];

struct SegmentTree {

    int strt, nd;
    Tuple vals;
    SegmentTree *lft, *rght;

    SegmentTree( ) { }
    SegmentTree( int strt, int nd ) : strt( strt ), nd( nd ) {
        if( strt == nd ) {
            vals = Tuple( ( X[ strt ] < 0 ), ( X[ strt ] == 0 ), ( X[ strt ] > 0 ) );
            lft = rght = NULL;
            return ;
        }
        int md = ( strt+nd )/2;
        lft  = new SegmentTree( strt, md );
        rght = new SegmentTree( md+1, nd );
        vals = lft->vals + rght->vals;
    }

    void update( int node ) {
        if( strt == nd ) {
            vals = Tuple( ( X[ strt ] < 0 ), ( X[ strt ] == 0 ), ( X[ strt ] > 0 ) );
            return ;
        }
        int md = ( strt+nd )/2;
        if( node <= md ) lft->update( node );
        else             rght->update( node );
        vals = lft->vals + rght->vals;
    }

    Tuple query( int fr, int to ) {
        if( strt == fr && nd == to ) return vals;
        int md = ( strt+nd )/2;
        if( to <= md ) return lft->query( fr, to );
        if( fr >  md ) return rght->query( fr, to );
        return lft->query( fr, md ) + rght->query( md+1, to );
    }

};

inline int convert( int num ) {
    if( num > 0 ) return 1;
    if( num < 0 ) return -1;
    return num;
}

int main( ) {

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( cin >> N >> K ) {
        for( int i = 1; i <= N; i++ ) {
            cin >> X[ i ];
            X[ i ] = convert( X[ i ] );
        }
        SegmentTree st( 1, N );
        for( int i = 0; i < K; i++ ) {
            cin >> Op >> F >> T;
            if( Op == 'C' ) {
                X[ F ] = convert( T );
                st.update( F );
            }
            else {
                Tuple tmp = st.query( F, T );
                if( tmp.z ) cout << "0";
                else if( tmp.n&1 ) cout << "-";
                else cout << "+";
            }
        }
        cout << "\n";
    }

    return 0;
}
