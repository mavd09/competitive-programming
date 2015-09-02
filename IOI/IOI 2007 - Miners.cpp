#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <queue>
#include <math.h>
#include <cstring>
#include <cstdlib>

#define MP   make_pair
#define PB   push_back
#define FI   first
#define SE   second
#define Edge pair< int, int >

#define MAXN 100000
#define MAXS 10

#define INF  ( 1<<29 )

typedef long long ll;

using namespace std;
//                                   00  01  02  03  04  05  06  07  08  09 
//                                  "  ""MM""MB""MF""BM""BB""BF""FM""FB""FF"
const int nextState[ 3 ][ 13 ] = { {  1,  1,  4,  7,  1,  4,  7,  1,  4,  7 },
				                   {  5,  2,  5,  8,  2,  5,  8,  2,  5,  8 },
                                   {  9,  3,  6,  9,  3,  6,  9,  3,  6,  9 } };
const int value[ 3 ][ 13 ]     = { {  1,  1,  2,  2,  2,  2,  3,  2,  3,  2 },
				                   {  1,  2,  2,  3,  2,  1,  2,  3,  2,  2 },
				                   {  1,  2,  3,  2,  3,  2,  2,  2,  2,  1 } };

int n, c;
string f;

int dp[ 2 ][ MAXS ][ MAXS ];
int ans;

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
  
    memset( dp, -1, sizeof( dp ) );

    cin >> n >> f;

    ans = 1;

    c = ( f[ 0 ] == 'M' ? 0 : ( f[ 0 ] == 'B' ? 1 : 2 ) );
    dp[ 0 ][ nextState[ c ][ 0 ] ][ 0 ] = 1;
    dp[ 0 ][ 0 ][ nextState[ c ][ 0 ] ] = 1;

    for( int i = 1; i < n; i++ ) {
    
        c = ( f[ i ] == 'M' ? 0 : ( f[ i ] == 'B' ? 1 : 2 ) );
    
        for( int stateA = 0; stateA < MAXS; stateA++ ) {
            for( int stateB = 0; stateB < MAXS; stateB++ ) {
                if( dp[ 0 ][ stateA ][ stateB ] == -1 ) continue;
                dp[ 1 ][ nextState[ c ][ stateA ] ][ stateB ] = max( dp[ 1 ][ nextState[ c ][ stateA ] ][ stateB ], dp[ 0 ][ stateA ][ stateB ]+value[ c ][ stateA ] );
                dp[ 1 ][ stateA ][ nextState[ c ][ stateB ] ] = max( dp[ 1 ][ stateA ][ nextState[ c ][ stateB ] ], dp[ 0 ][ stateA ][ stateB ]+value[ c ][ stateB ] );
            }
        }
    
        for( int stateA = 0; stateA < MAXS; stateA++ ) {
            for( int stateB = 0; stateB < MAXS; stateB++ ) {
                dp[ 0 ][ stateA ][ stateB ] = dp[ 1 ][ stateA ][ stateB ];
                dp[ 1 ][ stateA ][ stateB ] = -1;
                ans = max( ans, dp[ 0 ][ stateA ][ stateB ] );
            }
        }

    }

    cout << ans << "\n";

    return 0;

}
