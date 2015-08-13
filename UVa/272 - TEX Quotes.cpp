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

string line;

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    bool f = 0;
    while( getline( cin, line ) ) {
        for( int i = 0; i < int( line.size( ) ); i++ ) {
            if( line[ i ] == '\"' ) {
                if( !f ) cout << "``";
                else cout << "\'\'";
                f = !f;
            }
            else cout << line[ i ];
        }
        cout << "\n";
    }

    return 0;
}
