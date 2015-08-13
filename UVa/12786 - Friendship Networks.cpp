#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int( 2000 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int n, d[ MAX ];

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( cin >> n ) {
		for( int i = 0; i < n; i++ ) cin >> d[ i ];
		bool can = true;
		for( int i = n-1; i >= 0; i-- ) {
			sort( d, d+i+1 );
			for( int j = i-1; j > i-1-d[ i ]; j-- ) {
				if( d[ j ] == 0 ) can = false;
				d[ j ]--;
			}
			if( !can ) break;
		}
		cout << can << "\n";
	}

    return 0;
}
