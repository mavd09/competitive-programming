#include <bits/stdc++.h>

#define PB  push_back
#define MP  make_pair
#define FI  first
#define SE  second

#define MAX 100100
#define INF INT_MAX/10

using namespace std;

int n;
int dp[ MAX ];
vector< int > f;

int main( ) {

    for( int i = 0; i < MAX; i++ ) dp[ i ] = INF;
    for( int i = 1, j = 2; i < MAX ; i *= j, j++ ) f.PB( i ), dp[ i ] = 1;

    for( int i = 0; i < int( f.size( ) ); i++ ) {
        for( int j = 1; j < MAX; j++ ) {
            if( j+f[ i ] >= MAX ) continue;
            dp[ j+f[ i ] ] = min( dp[ j+f[ i ] ], dp[ j ]+1 );
        }
    }

    while( cin >> n ) cout << dp[ n ] << "\n";

    return 0;
}
