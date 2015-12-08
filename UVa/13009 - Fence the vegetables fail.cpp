#include <bits/stdc++.h>

#define MP          make_pair
#define PB          push_back
#define FI          first
#define SE          second

#define MAX         10100
#define LOG_MAX     14

#define MAX_PRIMES  1245

#define INF         ( INT_MAX )/10

#define MOD         1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

struct SegmentTree {
    int strt, nd;
    int val, lazy;
    SegmentTree *lft, *rght;
    SegmentTree( ) { }
    void create( ) {
        if( strt != nd && lft == nullptr && rght == nullptr ) {
            int md = ( strt+nd )/2;
            lft = new SegmentTree( strt, md );
            rght = new SegmentTree( md+1, nd );
        }
    }
    SegmentTree( int strt, int nd ) : strt( strt ), nd( nd ) {
        val = lazy = 0;
        lft = rght = nullptr;
    }
    void propagate( ) {
        create( );
        if( lazy ) {
            val = ( val+lazy )%2;
            if( strt != nd ) {
                lft->lazy = ( lft->lazy+lazy )%2;
                rght->lazy = ( rght->lazy+lazy )%2;
            }
        }
        lazy = 0;
    }
    void update( int f, int t ) {
        propagate( );
        if( strt == f && nd == t ) {
            lazy = ( lazy+1 )%2;
            propagate( );
            return ;
        }
        if( t <= lft->nd ) lft->update( f, t );
        else if( f >= rght->strt ) rght->update( f, t );
        else {
            lft->update( f, lft->nd );
            rght->update( rght->strt, t );
        }
        lft->propagate( );
        rght->propagate( );
        val = ( lft->val+rght->val )%2;
    }
    int query( int y ) {
        propagate( );
        if( strt == nd ) return val = val%2;
        if( y <= lft->nd ) return lft->query( y );
        return rght->query( y );
    }
};

struct BIT {
    int n;
    vector< int > bit;
    BIT( ) { }
    BIT( int n ) : n( n ), bit( n, 0 ) { }
    void update( int i, int val ) {
        for( ; i < n; i += ( i&(-i) ) )
            bit[ i ] += val;
    }
    void updateRange( int f, int t ) {
        update( f, 1 );
        update( t+1, -1 );
    }
    int query( int i ) {
        int ret = 0;
        for( ; i != 0; i -= ( i&(-i) ) )
            ret += bit[ i ];
        return ret%2;
    }
};

int getPos( vector< int >& s, int val ) {
    return int( lower_bound( s.begin( ), s.end( ), val )-s.begin( ) );
}

int main( ) {
    
    int p, v;
    
    while( scanf( "%d %d", &p, &v ) == 2 ) {
        vector< int > x, y;
        vector< pair< int, int > > P( p );
        for( auto& e : P ) {
            scanf( "%d %d", &e.FI, &e.SE );
            x.PB( e.FI );
            y.PB( e.SE );
        }
        vector< pair< int, int > > V( v );
        for( auto& e : V ) {
            scanf( "%d %d", &e.FI, &e.SE );
            x.PB( e.FI );
            y.PB( e.SE );
        }
        sort( x.begin( ), x.end( ) );
        x.resize( unique( x.begin( ), x.end( ) )-x.begin( ) );
        sort( y.begin( ), y.end( ) );
        y.resize( unique( y.begin( ), y.end( ) )-y.begin( ) );
        int tam = int( x.size( ) ), id = 1;
        vector< vector< pair< int, int > > > cP( tam ), cV( tam );
        for( auto& e : P ) {
            e.FI = getPos( x, e.FI );
            e.SE = getPos( y, e.SE );
            cP[ e.FI ].PB( MP( e.SE, id++ ) );
        }
        for( int i = 0; i < v; i++ ) {
            auto& e = V[ i ];
            e.FI = getPos( x, e.FI );
            e.SE = getPos( y, e.SE );
        }
        V.PB( V[ 0 ] );
        for( int i = 0; i+1 <= v; i++ ) {
            auto& e1 = V[ i ];
            auto& e2 = V[ i+1 ];
            if( e1.FI == e2.FI ) {
                cV[ e1.FI ].PB( MP( min( e1.SE, e2.SE ), max( e1.SE, e2.SE ) ) );
                i++;
            }
        }
        ll ans = 0;
        //SegmentTree st( 0, int( y.size( ) ) );
        BIT bt( int( y.size( ) ) );
        for( int i = 0; i < tam; i++ ) {
            for( int j = 0; j < int( cV[ i ].size( ) ); j++ ) {
                auto& e = cV[ i ][ j ];
                //st.update( e.FI+1, e.SE );
                bt.updateRange( e.FI+1, e.SE );
            }
            for( int j = 0; j < int( cP[ i ].size( ) ); j++ ) {
                auto& e = cP[ i ][ j ];
                //if( !st.query( e.FI ) ) ans += ll( e.SE );
                if( !bt.query( e.FI ) ) ans += ll( e.SE );
            }
        }
        printf( "%lld\n", ans );
    }
    
    return 0;
}