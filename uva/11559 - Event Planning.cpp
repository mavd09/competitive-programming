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

int n, b, h, w, p, a, ans;

int main( ) {

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( cin >> n >> b >> h >> w ) {
        ans = INF;
        while( h-- ) {
            cin >> p;
            int cur = INF, tmpW = w;
            while( tmpW-- ) {
                cin >> a;
                if( a >= n ) cur = p*n;
            }
            ans = min( ans, cur );
        }
        if( ans > b ) cout << "stay home\n";
        else cout << ans << "\n";
    }

    return 0;
}
