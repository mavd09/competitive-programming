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
typedef unsigned long long ull;

using namespace std;

const int dx[ ] = {  0  ,  0  ,  1  , -1  };
const int dy[ ] = {  1  , -1  ,  0  ,  0  };

int r, c;
vector< vector< int > > b( MAX, vector< int >( MAX ) );

inline bool isValid( int x, int y ) { return 0 <= x && x < r && 0 <= y && y < c; }

int bfs( ) {
    vector< vector< bool > > used( MAX, vector< bool >( MAX, false ) );
    int u, v, nu, nv, ret = 0;
    queue< int > q;
    for( int i = 0; i < r; i++ ) {
        for( int j = 0; j < c; j++ ) {
            if( !used[ i ][ j ] ) {
                ret++;
                q.push( i );
                q.push( j );
                used[ i ][ j ] = true;
                while( !q.empty( ) ) {
                    u = q.front( ); q.pop( );
                    v = q.front( ); q.pop( );
                    assert( isValid( u, v ) );
                    for( int k = 0; k < 4; k++ ) {
                        nu = u+dx[ k ];
                        nv = v+dy[ k ];
                        if( isValid( nu, nv ) && !used[ nu ][ nv ] && b[ nu ][ nv ] == b[ u ][ v ] ) {
                            used[ nu ][ nv ] = true;
                            q.push( nu );
                            q.push( nv );
                        }
                    }
                }
            }
        }
    }
    return ret;
}

void rot( ) {
    vector< vector< int > > ret( MAX, vector< int >( MAX ) );
    for( int i = 0; i < r; i++ )
        for( int j = 0; j < c; j++ )
            ret[ j ][ r-i-1 ] = b[ i ][ j ];
    b = ret;
    swap( r, c );
}

int go( ) {
    int ret = 0, lstState, curState;
    for( int i = 0; i < r-1; i++ ) {
        if( b[ i ][ 0 ] == b[ i+1 ][ 0 ] ) lstState = 0;
        else {
            lstState = 1+( b[ i ][ 0 ] > b[ i+1 ][ 0 ] );
            ret++;
        }
        for( int j = 1; j < c; j++ ) {
            if( b[ i ][ j ] == b[ i+1 ][ j ] ) {
                lstState = 0;
                continue;
            }
            curState = 1+( b[ i ][ j ] > b[ i+1 ][ j ] );
            if( curState != lstState ) {
                ret++;
                lstState = curState;
            }
            else {
                if( curState == 1 )
                    ret += !( min( b[ i+1 ][ j-1 ], b[ i+1 ][ j ] ) > max( b[ i ][ j-1 ], b[ i ][ j ] ) );
                else
                    ret += !( min( b[ i ][ j-1 ], b[ i ][ j ] ) > max( b[ i+1 ][ j-1 ], b[ i+1 ][ j ] ) );
            }
        }
    }
    return ret;
}

int solve( ) {
    int ans = 5+bfs( );
    ans += go( );
    rot( );
    ans += go( );
    return ans;
}

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    while( cin >> r >> c ) {
        for( int i = 0; i < r; i++ )
            for( int j = 0; j < c; j++ )
                cin >> b[ i ][ j ];
        cout << solve( ) << "\n";
    }
    
    return 0;
}