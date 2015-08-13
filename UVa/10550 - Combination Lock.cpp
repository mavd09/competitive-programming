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

int iniPos, a, b, c;

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( ( cin >> iniPos >> a >> b >> c ) && iniPos+a+b+c > 0 ) {
        int ans = 0;
        ans += 720;
        if( iniPos >= a ) ans += 360/40 * ( iniPos-a );
        else              ans += 360/40 * ( iniPos+40-a );
        ans += 360;
        if( a <= b ) ans += 360/40 * ( b-a );
        else         ans += 360/40 * ( 40-a+b );
        if( b >= c ) ans += 360/40 * ( b-c );
        else         ans += 360/40 * ( b+40-c );
        cout << ans << "\n";
    }

    return 0;
}
