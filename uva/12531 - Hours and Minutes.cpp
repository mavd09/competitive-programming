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

int A;
int h, m, cur;
bool can[ 500 ];

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( !( h == 360 && m == 0 ) ) {
        can[ 360-abs(h-m) ] = can[ abs(h-m) ] = true;
        if( cur == 0 ) h += 6;
        cur = ( cur+1 )%12;
        m = (m+6)%360;
    }

    while( scanf( "%d", &A ) != EOF ) printf( "%c\n", ( can[ A ] ? 'Y' : 'N' ) );

    return 0;
}
