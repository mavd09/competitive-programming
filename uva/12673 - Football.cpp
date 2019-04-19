#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int( 1e5+10 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int n, g;
pair< int, int > m[ MAX ];

bool cmp( pair< int, int > a, pair< int, int > b ) {
    return ( a.FI-a.SE ) > ( b.FI-b.SE );
}

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( cin >> n >> g ) {
        for( int i = 0; i < n; i++ ) cin >> m[ i ].FI >> m[ i ].SE;
        sort( m, m+n, cmp );
        int ans = 0;
        for( int i = 0; i < n; i++ ) {
            if( m[ i ].FI > m[ i ].SE ) ans += 3;
            if( m[ i ].FI == m[ i ].SE ) {
                if( g ) g--, ans += 3;
                else    ans += 1;
            }
            if( m[ i ].FI < m[ i ].SE ) {
                int tmp = min( g, m[ i ].SE-m[ i ].FI );
                g -= tmp;
                m[ i ].FI += tmp;
                if( g ) g--, m[ i ].FI++;
                if( m[ i ].FI > m[ i ].SE )  ans += 3;
                if( m[ i ].FI == m[ i ].SE ) ans += 1;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
