#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int( 100 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int n, m, c, power, id, ans;
int C[ MAX ];
bool used[ MAX ];

int main( ) {

	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );
	cout.tie( 0 );

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    for( int tc = 1; ( cin >> n >> m >> c ) && ( n+m+c > 0 ); tc++ ) {
        memset( used, false, sizeof( used ) );
        power = 0; ans = 0;
        for( int i = 1; i <= n; i++ ) cin >> C[ i ];
        for( int i = 0; i < m; i++ ) {
            cin >> id;
            if( used[ id ] ) power -= C[ id ];
            else             power += C[ id ];
            used[ id ] = !used[ id ];
            ans = max( ans, power );
        }
        cout << "Sequence " << tc << "\n";
        if( ans > c ) cout << "Fuse was blown.\n\n";
        else          cout << "Fuse was not blown.\nMaximal power consumption was " << ans << " amperes.\n\n";
    }

    return 0;
}
