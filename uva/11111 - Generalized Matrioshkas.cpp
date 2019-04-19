#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    m   ake_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAXN 	int( 1e7+100 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

string line;
int sz;
ll a[ MAXN ], b[ MAXN ], c;
bool can;

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( getline( cin, line ) ) {

        can = true;
        sz  = 0;

        stringstream ss( line );
        while( ss >> c ) {
            if( c < 0 ) {
                a[ sz ] = -c;
                b[ sz ] = 0;
                if( sz ) {
                    b[ sz-1 ] += -c;
                    if( b[ sz-1 ] >= a[ sz-1 ] ) can = false;
                }
                sz++;
            }
            else {
                if( sz == 0 || a[ sz-1 ] != c ) can = false;
                sz--;
            }
            if( !can ) break;
        }
        can &= !sz;
        if( can ) cout << ":-) Matrioshka!\n";
        else      cout << ":-( Try again.\n";

    }

    return 0;
}
