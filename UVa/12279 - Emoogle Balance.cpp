#include <bits/stdc++.h>

#define FILE 	1
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

int n, x, t;

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( ( cin >> n ) && ( n > 0 ) ) {
        int ans = 0;
        for( int i = 0; i < n; i++ ) {
            cin >> x;
            ans += ( x == 0 ? -1 : 1 );
        }
        cout << "Case " << ++t << ": " << ans << "\n";
    }

    return 0;
}
