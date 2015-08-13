#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int(1e7+10)
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int nTest, v;
string url;

int main( ) {

	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );
	cout.tie( 0 );

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    cin >> nTest;
    for( int tc = 1; nTest--; tc++ ) {
        vector< string > ans;
        int best = 0;
        for( int i = 1; i <= 10; i++ ) {
            cin >> url >> v;
            if( v > best ) {
                best = v;
                ans.clear( );
            }
            if( best == v ) ans.PB( url );
        }
        cout << "Case #" << tc << ":\n";
        for( int i = 0; i < int( ans.size( ) ); i++ ) cout << ans[ i ] << "\n";
    }

    return 0;
}
