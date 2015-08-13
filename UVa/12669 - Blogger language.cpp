#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int( 2e5+1000 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int nQueries, n, szP, szT;
int f[ MAX ], t[ MAX ];
string P, T, p[ MAX ];

inline int dist( string a, string b, int sz ) {
    int ret = 0;
    for( int i = 0; i < sz; i++ ) ret += ( a[ i ] != b[ i ] );
    return ret;
}

struct SegmentTree {

    int strt, nd;
    int a, b;
    int mn, mx;
    int lazy;
    SegmentTree *lft, *rght;

    SegmentTree( ) { }
    SegmentTree( int strt, int nd ) : strt( strt ), nd( nd ) {
        lazy = 0;
        if( strt == nd ) {
            a = f[ strt ];
            b = t[ strt ];
            mn = mx = dist( p[ strt ], P, szP );
            lft = rght = NULL;
            return ;
        }
        int md = ( strt+nd )/2;
        lft  = new SegmentTree( strt, md );
        rght = new SegmentTree( md+1, nd );
        a = lft->a;
        b = rght->b;
        mn = min( lft->mn, rght->mn );
        mx = max( lft->mx, rght->mx );
    }

    void propagate( ) {
        if( lazy ) {
            int tmp = mn;
            mn = szP-mx;
            mx = szP-tmp;
            if( strt != nd ) {
                lft->lazy = 1-lft->lazy;
                rght->lazy = 1-rght->lazy;
            }
            else {
                for( int i = 0; i < szP; i++ ) {
                    if( 'a' <= p[ strt ][ i ] && p[ strt ][ i ] <= 'z' ) p[ strt ][ i ] = toupper( p[ strt ][ i ] );
                    else p[ strt ][ i ] = tolower( p[ strt ][ i ] );
                }
            }
            lazy = 0;
        }
    }

    int query( int fr, int to ) {
        propagate( );
        if( fr > b || to < a ) return -1;
        if( strt == nd ) {
            int ans = mx;
            int limA = max( fr, a );
            int limB = min( to, b );
            for( int i = 0, j = a; j <= b; i++, j++ ) {
                if( !( limA <= j && j <= limB ) ) continue;
                if( 'a' <= p[ strt ][ i ] && p[ strt ][ i ] <= 'z' ) p[ strt ][ i ] = toupper( p[ strt ][ i ] );
                else p[ strt ][ i ] = tolower( p[ strt ][ i ] );
            }
            mn = mx = dist( p[ strt ], P, szP );
            if( limA == a && limB == b ) return ans;
            return -1;
        }
        if( fr <= a && b <= to ) {
            int ans = mx;
            lazy = 1;
            propagate( );
            return ans;
        }
        int ans = -1;
        ans = max( ans, lft->query( fr, to ) );
        ans = max( ans, rght->query( fr, to ) );
        mn = min( lft->mn, rght->mn );
        mx = max( lft->mx, rght->mx );
        return ans;
    }

};

int main( ) {

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( cin >> nQueries >> P >> T ) {
        szP = int( P.size( ) );
        szT = int( T.size( ) );
        n = 0;
        for( int i = 0; i < szT; i++ ) {
            if( tolower( T[ i ] ) == tolower( P[ 0 ] ) ) {
                bool found = true;
                string tmp = string( 1, T[ i ] );
                for( int j = 1; j < szP; j++ ) {
                    found &= ( tolower( T[ i+j ] ) == tolower( P[ j ] ) );
                    tmp += T[ i+j ];
                }
                if( found ) {
                    p[ n ] = tmp;
                    f[ n ] = i;
                    t[ n ] = i+szP-1;
                    n++;
                }
            }
        }
        int fr, to;
        if( n ) {
            SegmentTree st( 0, n-1 );
            for( int i = 0; i < nQueries; i++ ) {
                cin >> fr >> to;
                cout << st.query( fr-1, to-1 ) << "\n";
            }
        }
        else {
            for( int i = 0; i < nQueries; i++ ) {
                cin >> fr >> to;
                cout << -1 << "\n";
            }
        }
    }

    return 0;
}
