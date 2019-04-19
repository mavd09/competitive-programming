#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int( 200 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int nTest, n, p, id;
int instruction[ MAX ];
string op;

int main( ) {

	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );
	cout.tie( 0 );

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    cin >> nTest;
    while( nTest-- ) {
        cin >> n;
        p = 0;
        for( int i = 1; n--; i++ ) {
            cin >> op;
            if( op == "LEFT" )  instruction[ i ] = -1;
            if( op == "RIGHT" ) instruction[ i ] = 1;
            if( op == "SAME" ) {
                cin >> op >> id;
                instruction[ i ] = instruction[ id ];
            }
            p += instruction[ i ];
        }
        cout << p << "\n";
    }

    return 0;
}
