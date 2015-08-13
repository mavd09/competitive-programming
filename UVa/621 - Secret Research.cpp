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

int nTest, sz;
string n;
char last;

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    cin >> nTest;
    while( nTest-- ) {
        cin >> n;
        sz = int( n.size( ) );
        if( n == "1" || n == "4" || n == "78" )                              cout << "+\n", last = '+';
        else if( sz > 1 && n[ sz-2 ] == '3' && n[ sz-1 ] == '5' )            cout << "-\n", last = '-';
        else if( sz > 1 && n[ 0 ] == '9' && n[ sz-1 ] == '4' )               cout << "*\n", last = '*';
        else if( sz > 3 && n[ 0 ] == '1' && n[ 1 ] == '9' && n[ 2 ] == '0' ) cout << "?\n", last = '?';
        else                                                                 cout << last << "\n";
    }

    return 0;
}
