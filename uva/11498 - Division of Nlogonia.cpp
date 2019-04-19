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

int k, dx, dy, x, y;

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( ( cin >> k ) && ( k > 0 ) ) {
        cin >> dx >> dy;
        for( int i = 0; i < k; i++ ) {
            cin >> x >> y;
            if( dx ==  x || dy ==  y ) cout << "divisa\n";
            if(  x <  dx && dy <   y ) cout << "NO\n";
            if(  x <  dx &&  y <  dy ) cout << "SO\n";
            if( dx <   x && dy <   y ) cout << "NE\n";
            if( dx <   x &&  y <  dy ) cout << "SE\n";
        }
    }


    return 0;
}
