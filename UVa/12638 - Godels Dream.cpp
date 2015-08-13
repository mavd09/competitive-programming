#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int( 1e4+10 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int sz;
string s;
int dp[ MAX ];

int main( ) {

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( cin >> s ) {
        sz = int( s.size( ) );
        bool can = true;
        dp[ sz ] = 0;
        for( int i = sz-1; i >= 0; i-- ) {
            if( s[ i ] == '1' ) {
                if( dp[ i+1 ] > 1 ) dp[ i ] = dp[ i+1 ]-1;
                else {
                    can = false;
                    break;
                }
            }
            else dp[ i ] = dp[ i+1 ]+1;
        }
        if( can ) cout << dp[ 0 ] << "\n";
        else cout << 0 << "\n";
    }

    return 0;
}
