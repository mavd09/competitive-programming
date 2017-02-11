#include <bits/stdc++.h>

#define PB  push_back
#define MP  make_pair
#define FI  first
#define SE  second

#define MAX 2010

using namespace std;

string s;
int n;
int dp[ MAX ][ MAX ], aux[ MAX ][ MAX ];
int v[ MAX ];

int main( ) {

    while( cin >> s >> n ) {
        memset( v, 0, sizeof( v ) );
        memset( dp, 0, sizeof( dp ) );
        memset( aux, 0, sizeof( aux ) );
        for( int i = 0, u; i < n; i++ ) {
            cin >> u;
            u--;
            v[ u ] = true;
        }
        int sz = int( s.size( ) ), ans = 0, ans2 = 0;
        for( int i = 0; i < sz; i++ ) dp[ i ][ i ] = 1, aux[ i ][ i ] = v[ i ];
        for( int i = 1; i < sz; i++ ) {
            dp[ i-1 ][ i ] = 1;
            aux[ i-1 ][ i ] = max( aux[ i-1 ][ i-1 ], v[ i ] );
            if( s[ i ] == s[ i-1 ] ) dp[ i-1 ][ i ] = 2, aux[ i-1 ][ i ] = v[ i ]+v[ i-1 ];
        }
        for( int j = 2; j < sz; j++ ) {
            for( int i = 0, k = j; k < sz; i++, k++ ) {
                if( s[ i ] == s[ k ] ) {
                    if( aux[ i+1 ][ k-1 ]+v[ i ]+v[ k ] > aux[ i ][ k-1 ] && aux[ i+1 ][ k-1 ]+v[ i ]+v[ k ] > aux[ i+1 ][ k ] ) {
                        dp[ i ][ k ] = dp[ i+1 ][ k-1 ]+2;
                        aux[ i ][ k ] = aux[ i+1 ][ k-1 ]+v[ i ]+v[ k ];
                    }
                    else if( aux[ i+1 ][ k-1 ]+v[ i ]+v[ k ] < aux[ i ][ k-1 ] && aux[ i+1 ][ k ] < aux[ i ][ k-1 ] ) {
                        dp[ i ][ k ] = dp[ i ][ k-1 ];
                        aux[ i ][ k ] = aux[ i ][ k-1 ];
                    }
                    else if( aux[ i+1 ][ k ] > aux[ i ][ k-1 ] && aux[ i+1 ][ k ] > aux[ i+1 ][ k-1 ]+v[ i ]+v[ k ] ) {
                        dp[ i ][ k ] = dp[ i+1 ][ k ];
                        aux[ i ][ k ] = aux[ i+1 ][ k ];
                    }
                    else {
                        if( aux[ i+1 ][ k ] == aux[ i ][ k-1 ] && aux[ i+1 ][ k ] == aux[ i+1 ][ k-1 ]+v[ i ]+v[ k ] ) {
                            aux[ i ][ k ] = aux[ i+1 ][ k ];
                            dp[ i ][ k ] = max( dp[ i+1 ][ k ], max( dp[ i ][ k-1 ], dp[ i+1][ k-1 ]+2 ) );
                        }
                        else if( aux[ i+1 ][ k ] == aux[ i+1 ][ k-1 ]+v[ i ]+v[ k ] ) {
                            aux[ i ][ k ] = aux[ i+1 ][ k ];
                            dp[ i ][ k ] = max( dp[ i+1 ][ k ], dp[ i+1 ][ k-1 ]+2 );
                        }
                        else if( aux[ i+1 ][ k ] == aux[ i ][ k-1 ] ) {
                            aux[ i ][ k ] = aux[ i+1 ][ k ];
                            dp[ i ][ k ] = max( dp[ i+1 ][ k ], dp[ i ][ k-1 ] );
                        }
                        else if( aux[ i+1 ][ k-1 ]+v[ i ]+v[ k ] == aux[ i ][ k-1 ] ) {
                            aux[ i ][ k ] = aux[ i ][ k-1 ];
                            dp[ i ][ k ] = max( dp[ i+1 ][ k-1 ]+2, dp[ i ][ k-1 ] );
                        }
                    }
                }
                else {
                    if( aux[ i ][ k-1 ] > aux[ i+1 ][ k ] ) {
                        dp[ i ][ k ] = dp[ i ][ k-1 ];
                        aux[ i ][ k ] = aux[ i ][ k-1 ];
                    }
                    else if( aux[ i ][ k-1 ] < aux[ i+1 ][ k ] ) {
                        dp[ i ][ k ] = dp[ i+1 ][ k ];
                        aux[ i ][ k ] = aux[ i+1 ][ k ];
                    }
                    else {
                        dp[ i ][ k ] = max( dp[ i+1 ][ k ], dp[ i ][ k-1 ] );
                        aux[ i ][ k ] = aux[ i+1 ][ k ];
                    }
                }
            }
        }

        cout << dp[ 0 ][ sz-1 ] << "\n";
    }

    return 0;
}
