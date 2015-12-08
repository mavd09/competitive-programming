/* Wrong Answer */
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>

#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <set>
#include <deque>
#include <utility>
#include <sstream>
#include <queue>
#include <stack>
#include <bitset>

#include <math.h>
#include <iomanip>
#include <algorithm>
#include <limits.h>

#include <complex.h>
#include <assert.h>

#define MP          make_pair
#define PB          push_back
#define FI          first
#define SE          second

#define MAX         110
//#define LOG_MAX     14

#define MAX_PRIMES  1245

#define INF         ( INT_MAX )

#define MOD         1000000007
typedef unsigned long long ull;

using namespace std;

const int dx[ ] = {  0  ,  0  ,  1  , -1  };
const int dy[ ] = {  1  , -1  ,  0  ,  0  };

int r, c;
int b[ MAX ][ MAX ];
bool used[ MAX ][ MAX ];

inline bool isValid( int x, int y ) { return 0 <= x && x < r && 0 <= y && y < c; }

int bfs1( ) {
    memset( used, false, sizeof( used ) );
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

int bfs2( int strt, int nd, int d ) {
    memset( used, false, sizeof( used ) );
    int u, v, nu, nv, ret = 0;
    queue< int > q;
    for( int i = strt; i != nd; i += d ) {
        for( int j = 0; j < c; j++ ) {
            if( !used[ i ][ j ] ) {
                ret++;
                for( int k = 0; j+k < c && !used[ i ][ j+k ]; k++ ) {
                    q.push( i );
                    q.push( j+k );
                    used[ i ][ j+k ] = true;
                }
                while( !q.empty( ) ) {
                    u = q.front( ); q.pop( );
                    v = q.front( ); q.pop( );
                    nu = u+d;
                    nv = v;
                    if( isValid( nu, nv ) && !used[ nu ][ nv ] && b[ nu ][ nv ] <= b[ u ][ v ] ) {
                        used[ nu ][ nv ] = true;
                        q.push( nu );
                        q.push( nv );
                    }
                }
            }
        }
    }
    return ret;
}

int bfs3( int strt, int nd, int d ) {
    memset( used, false, sizeof( used ) );
    int u, v, nu, nv, ret = 0;
    queue< int > q;
    for( int j = strt; j != nd; j += d ) {
        for( int i = 0; i < r; i++ ) {
            if( !used[ i ][ j ] ) {
                ret++;
                for( int k = 0; i+k < r && !used[ i+k ][ j ]; k++ ) {
                    q.push( i+k );
                    q.push( j );
                    used[ i+k ][ j ] = true;
                }
                while( !q.empty( ) ) {
                    u = q.front( ); q.pop( );
                    v = q.front( ); q.pop( );
                    nu = u;
                    nv = v+d;
                    if( isValid( nu, nv ) && !used[ nu ][ nv ] && b[ nu ][ nv ] <= b[ u ][ v ] ) {
                        used[ nu ][ nv ] = true;
                        q.push( nu );
                        q.push( nv );
                    }
                }
            }
        }
    }
    return ret;
}

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    while( cin >> r >> c ) {
        for( int i = 0; i < r; i++ )
            for( int j = 0; j < c; j++ )
                cin >> b[ i ][ j ];
        cout << 1+bfs1( )+bfs2( 0, r, 1 )+bfs2( r-1, -1, -1 )+bfs3( 0, c, 1 )+bfs3( c-1, -1, -1 ) << "\n";
    }
    
    return 0;
}

/*
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>

#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <set>
#include <deque>
#include <utility>
#include <sstream>
#include <queue>
#include <stack>
#include <bitset>

#include <math.h>
#include <iomanip>
#include <algorithm>
#include <limits.h>

#include <complex.h>
#include <assert.h>

#define MP          make_pair
#define PB          push_back
#define FI          first
#define SE          second

#define MAX         100
//#define LOG_MAX     14

#define MAX_PRIMES  1245

#define INF         ( INT_MAX )

#define MOD         1000000007
typedef unsigned long long ull;

using namespace std;

enum colors_t {black = 1, blue, green, cyan, red, purple, yellow, white};

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

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    colors_t a = red;
    cout << a << endl;
    
    while( cin >> r >> c ) {
        for( int i = 0; i < r; i++ )
            for( int j = 0; j < c; j++ )
                cin >> b[ i ][ j ];
        int ans = 5+bfs( );
        ans += go( );
        rot( );
        ans += go( );
        cout << ans << "\n";
    }
    
    return 0;
}
*/