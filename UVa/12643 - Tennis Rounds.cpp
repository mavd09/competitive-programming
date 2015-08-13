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

int n, i, j, k, ans;

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( scanf( "%d %d %d", &n, &i, &j ) != EOF ) {
        for( ans = 0, k = 1; ; ans++, k *= 2 )
            if( int( ceil( (i*1.0)/(k*1.0) ) ) == int( ceil( (j*1.0)/(k *1.0) ) ) )
                break;
        printf( "%d\n", ans );
    }

    return 0;
}
