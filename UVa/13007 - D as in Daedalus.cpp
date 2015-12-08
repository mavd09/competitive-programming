#include <bits/stdc++.h>

#define MP          make_pair
#define PB          push_back
#define FI          first
#define SE          second

#define MAX         1000
//#define LOG_MAX     14

#define MAX_PRIMES  1245

//#define INF         ( INT_MAX )

#define MOD         1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    int nCards = 5;
    vector< int > card = { 0, 1, 10, 100, 1000, 10000 };
    
    int nPlayers, nRounds;
    
    while( cin >> nPlayers >> nRounds ) {
        vector< int > c( nPlayers );
        int expectedWon = 0, totalWon = 0;
        while( nRounds-- ) {
            int b, sum = 0;
            cin >> b;
            for( auto& e : c ) {
                cin >> e;
                sum += e;
            }
            if( sum <= b ) totalWon += c[ 0 ];
            sum -= c[ 0 ];
            for( int i = nCards; i >= 0; i-- ) {
                if( sum+card[ i ] <= b ) {
                    expectedWon += card[ i ];
                    break;
                }
            }
        }
        cout << expectedWon-totalWon << "\n";
    }
    
    return 0;
}