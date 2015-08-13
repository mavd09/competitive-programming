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

int x[ 5 ], y[ 5 ], ans;

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( cin >> x[ 0 ] ) {
        for( int i = 1; i < 5; i++ ) cin >> x[ i ];
        for( int i = 0; i < 5; i++ ) cin >> y[ i ];
        ans = 1;
        for( int i = 0; i < 5; i++ ) ans &= x[ i ]^y[ i ];

        cout << ( ans ? 'Y' : 'N' ) << "\n";
    }

    return 0;
}
