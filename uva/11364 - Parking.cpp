#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAXN 	int( 1e2 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

#define LOW     0
#define HIGH    100

typedef long long ll;

using namespace std;

int nTest, n, x, mn, mx;

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    cin >> nTest;
    while( nTest-- ) {
        cin >> n;
        mn = INF; mx = -1;
        for( int i = 1; i <= n; i++ ) {
            cin >> x;
            mn = min( mn, x );
            mx = max( mx, x );
        }
        cout << 2*(mx-mn) << "\n";
    }

    return 0;
}
