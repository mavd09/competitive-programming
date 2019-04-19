#include <bits/stdc++.h>

#define MP          make_pair
#define PB          push_back
#define FI          first
#define SE          second

#define MAX         10100
#define LOG_MAX     14

#define MAX_PRIMES  1245

#define INF         int(2e9)

#define EPS         1e-9

#define MOD         1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

struct SegmentTree {
    int strt, nd;
    int val;
    SegmentTree *lft, *rght;
    SegmentTree( ) { }
    SegmentTree( int strt, int nd ) : strt( strt ), nd( nd ) {
        val = INF;
        lft = rght = nullptr;
        if( strt == nd ) return ;
        int md = ( strt+nd )/2;
        lft = new SegmentTree( strt, md );
        rght = new SegmentTree( md+1, nd );
    }
    void update( int i, int v ) {
        if( strt == nd ) {
            val = v;
            return ;
        }
        if( i <= lft->nd ) lft->update( i, v );
        else rght->update( i, v );
        val = min( lft->val, rght->val );
    }
    int query( int f, int t ) {
        if( strt == f && nd == t ) return val;
        if( t <= lft->nd ) return lft->query( f, t );
        if( f >= rght->strt ) return rght->query( f, t );
        return min( lft->query( f, lft->nd ), rght->query( rght->strt, t ) );
    }
};

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    int n, m;
    
    while( cin >> n >> m ) {
        vector< int > e( n );
        vector< vector< pair< int, int > > > p( n );
        for( int i = 0; i < n; i++ ) {
            cin >> e[ i ];
            if( i ) e[ i ] += e[ i-1 ];
        }
        int l, s, c;
        for( int i = 0; i < m; i++ ) {
            cin >> l >> s >> c;
            p[ --l ].PB( MP( s, c ) );
        }
        SegmentTree st( 0, n );
        st.update( n, 0 );
        int ans = INF;
        int lo, hi, mi, sum;
        for( int lvl = n-1; lvl >= 0; lvl-- ) {
            ans = INF;
            for( int i = 0; i < int( p[ lvl ].size( ) ); i++ ) {
                lo = lvl; hi = n-1;
                while( lo <= hi ) {
                    mi = ( lo+hi )/2;
                    sum = e[ mi ];
                    if( lvl ) sum -= e[ lvl-1 ];
                    if( sum <= p[ lvl ][ i ].FI ) lo = mi+1;
                    else hi = mi-1;
                }
                if( lvl <= lo )
                    ans = min( ans, p[ lvl ][ i ].SE+st.query( lvl, lo ) );
            }
            st.update( lvl, ans );
        }
        if( ans == INF ) ans = -1;
        cout << ans << "\n";
    }
    
    return 0;
}