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

#define MAX         10020
#define LOG_MAX     14

#define MAX_PRIMES  1245

#define INF         ( INT_MAX )

#define MOD         1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int countPrimes;
int countFactors[ MAX ][ MAX_PRIMES ], cnt[ MAX_PRIMES ];

void sieve( ) {
    bitset< MAX > isPrime;
    isPrime.set( );
    isPrime[ 0 ] = isPrime[ 1 ] = 0;
    for( int i = 2; i < MAX; i++ ) {
        if( isPrime[ i ] ) {
            for( int j = i; j < MAX; j += i ) {
                if( i != j ) isPrime[ j ] = 0;
                int tmp = j;
                while( tmp%i == 0 ) {
                    countFactors[ j ][ countPrimes ]++;
                    tmp /= i;
                }
            }
            countPrimes++;
        }
        for( int j = 0; j < MAX_PRIMES; j++ )
            countFactors[ i ][ j ] += countFactors[ i-1 ][ j ];
    }
}

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    sieve( );

    int n, m, p, q;
    
    while( cin >> n >> m ) {
        memset( cnt, 0, sizeof( cnt ) );
        for( int i = 0; i < n; i++ ) {
            cin >> p;
            for( int j = 0; j < countPrimes; j++ )
                cnt[ j ] += countFactors[ p ][ j ];
        }
        bool can = true;
        for( int i = 0; i < m; i++ ) {
            cin >> q;
            for( int j = 0; j < countPrimes && can; j++ ) {
                cnt[ j ] -= countFactors[ q ][ j ];
                if( cnt[ j ] < 0 ) can = false;
            }
        }
        if( !can ) cout << -1 << "\n";
        else {
            vector< pair< int, int > > ans;
            for( int i = MAX-1; i > 1; i-- ) {
                int x = INF;
                for( int j = 0; j < countPrimes; j++ ) {
                    if( countFactors[ i ][ j ] == 0 ) continue;
                    x = min( x, cnt[ j ]/countFactors[ i ][ j ] );
                }
                if( x == 0 ) continue;
                for( int j = 0; j < countPrimes; j++ ) {
                    if( countFactors[ i ][ j ] == 0 ) continue;
                    cnt[ j ] -= x*countFactors[ i ][ j ];
                }
                ans.PB( MP( i, x ) );
            }
            cout << int( ans.size( ) ) << "\n";
            for( int i = 0; i < int( ans.size( ) ); i++ )
                cout << ans[ i ].FI << " " << ans[ i ].SE << "\n";
        }
    }
    
    
    return 0;
    
}