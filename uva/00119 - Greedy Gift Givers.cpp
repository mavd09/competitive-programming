#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int( 200 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int n, m, k, cur;
map< string, int > cnt;
string all[ MAX ], u, v;

int main( ) {

	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );
	cout.tie( 0 );

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    for( int tc = 0; cin >> n; tc++ ) {
        cnt.clear( );
        for( int i = 0; i < n; i++ ) {
            cin >> all[ i ];
            cnt[ all[ i ] ] = 0;
        }
        for( int i = 0; i < n; i++ ) {
            cin >> u >> m >> k;
            if( k == 0 ) continue;
            cur = m/k;
            cnt[ u ] -= cur*k;
            for( int j = 0; j < k; j++ ) {
                cin >> v;
                cnt[ v ] += cur;
            }
        }
        if( tc ) cout << "\n";
        for( int i = 0; i < n; i++ )
            cout << all[ i ] << " " << cnt[ all[ i ] ] << "\n";
    }

    return 0;
}
